//最差时间复杂度O(n方) 空间复杂度（1） 稳定 效率很差
#include<stdio.h>
#include<stdlib.h>
#include"swap.h"
#define MaxSize 20
#define MaxNum 60
int a[MaxSize];
void init() //生成随机数列
{
    for (int i = 0; i < MaxSize;i++)
    {
        a[i] = rand() % MaxNum;
        printf("%d ",a[i]);
    }
    puts("");
}
void pao()
{
    for (int i = 0; i < MaxSize-1;i++)//每趟完成一个数字的排序 一共需要n-1趟
    {
        for (int j = 0; j < MaxSize - 1 - i;j++)//每趟需要n-i-1次比较
        {
            if(a[j+1]<a[j])
                swap(a, j+1, j);
        }
    }
}
int main()
{
    init();
    pao();
    for (int i = 0; i < MaxSize;i++)
    {
        printf("%d ",a[i]);
    }
}