#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"swap.h"
#define maxsize 40
#define maxnum 30
int a[maxsize];
void id()
{
    for (int i = 1; i < maxsize ;i++)//第一个元素不用计算，因为只有一个的时候就是已经拍好的
    {
        int get = a[i];//要被插入的元素
        int left = 0;//排好元素的下界
        int right = i-1;//已经排好元素的上界
        while(left<=right)//当已经找到位置的时候
        {
            int mid = (left + right) / 2;//二分点
            if(a[mid]>get)//选择左右区域
                right = mid - 1;
            else
                left = mid + 1;
        }
        for (int j = i-1; j >= left;j--)//循环右移要插入点右边的元素
        {
            a[j+1] = a[j];
        }
        a[left] = get;//将元素插入
    }
}
int main()
{
    init(a, maxsize, maxnum);
    id();
    show(a, maxsize);
    return 0;
}