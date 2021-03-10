#include<stdio.h>
#include<stdlib.h>
#include"swap.h"
#define maxsize 30
#define maxnum 40
int a[maxsize];
void plg()
{
    for (int i = 1; i < maxsize;i++)//循环到最后一个
    {
        int j = i - 1;//从最后一个的前一个往前循环
        int temp = a[i];// 保存下来当前插入的数
        for (; a[j]>temp;j--)//循环将j设为找到需要插入的位置的前一个
        {
            a[j+1] = a[j];
        }
        a[j + 1] = temp;//将数字插入到j后面
    }
}
int main()
{
    init(a, maxsize, maxnum);
    plg();
    show(a,maxsize);
}