#include<stdio.h>
#include<stdlib.h>
#include"swap.h"
#define maxsize 30
#define maxnum 40
int a[maxsize];
void moto(int left,int right)
{
    while(left<right)
    {
        for (int i = left; i < right;i++)//每一轮循环左边的底应该为left
        {
            if(a[i]>a[i+1])
                swap(a, i, i + 1);
        }
        right--;
        for (int j = right; j > left;j--)//每一轮右边的底应该为right
        {
            if(a[j]<a[j-1])
                swap(a, j, j - 1);
        }
        left++;
    }
}
int main()
{
    init(a, maxsize, maxnum);
    moto(0, maxsize-1);//因为是坐标 所以应该是maxsize-1
    show(a, maxsize);
    return 0;
}