//并没有改变冒泡的本质  O（n平方）时间复杂度 空间复杂度 1
#include<stdio.h>
#include<stdlib.h>
#include"swap.h"
#define maxsize 20
#define maxnum 30
int a[maxsize];
void jwj()
{
    int left = 0; //左边的底
    int right = maxsize - 1;//右边的底
    while(left<right)//左边底等于右边底排序完毕
    {
        for (int i = left; i < right;i++)//从左向右冒泡排序一次
        {
            if(a[i+1]<a[i])
                swap(a, i, i + 1);
        }
        right--;//右边底已经确认一个 所以右边底减一
        for (int j = right; j > left;j--)//从右向左冒泡排序一次
        {
            if(a[j-1]>a[j])
                swap(a, j, j - 1);
        }
        left++;//从右向左将最小冒泡到前面，左边底加一
    }
}
int main()
{
    init(a, maxsize, maxnum);
    jwj();
    show(a, maxsize);
    return 0;
}