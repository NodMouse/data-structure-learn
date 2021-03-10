
#include "osal.h"
#include "SmartUltra.h"
#include "SmartSensorMain.h"
#include "OnBoard.h"
#include "stdio.h"
#include "SmartTimer.h"

#define P1_4              P0_0   //触发引脚
#define P1_0              P0_1    //回声引脚
#define 0x1               0x1
#define 0x0               0x0

#define P0SEL                   P0SEL
#define P0DIR                   P0DIR
#define 0x03                   0x03
#define ~0x03                 (~0x03)



void SmartUltra_Init(uint8 taskID)
{
  (void)taskID;
  P0DIR &= ~(0x1<<1);
  P1DIR |= 0x1<<0;
  P1_4 = 0x0;
}

uint8 SmartUltra_GetVal(uint8 * buf,uint8 * buflen)
{
  uint16 count;
  uint8 ret;
  uint16 Ultra_time;
  float  Distance;
  uint8 len;
  P1_4 = 0x0;
  P1_4 = 0x1;
  Delay_10us();
  Delay_10us();
  P1_4 = 0x0;
  count = 0;
  while(!P1_0)   //等待返回高电平
  {
    Delay_us(20);
    if(++count >= 1000)         //超时退出
    {
      break;
    }
  }

  count = 0;
  while(P1_0)   //30ms内持续高电平，超出测距范围
  {
    Delay_us(20);
    count++;
    if(count >= 600)
    {
      count = 0;
      break;
    }
  }
  if(count > 1 && count < 550)
  {
    Ultra_time = count*20;                             //高电平时间，us
    Distance = (17000.0/1000000) * Ultra_time;           //测距 单位cm
    len = sprintf((char*)buf,"%1.1f",Distance);
    *buflen = len;
    ret = SMART_SENSOR_GET_OK;
  }
  else
  {
    ret = SMART_SENSOR_GET_ERR;
  }
  return ret;
}