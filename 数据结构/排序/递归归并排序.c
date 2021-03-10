#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"swap.h"
#define maxsize 40
#define maxnum 30
int a[maxsize];
void merge(int *A,int left,int mid,int right)
{
    int len = right - left+1;
    int c[len];
    int temp = 0;
    int i = left;
    int j = mid+1;
    while(i<=mid && j<=right)
    {
        c[temp++] = A[i] >= A[j] ? A[j++] : A[i++];
    }//
        while(i<=mid)
        {
            c[temp++] = A[i++];
        }

        while(j<=right)//
        {
            c[temp++] = A[j++];
        }
        for (int k = 0; k < len;k++)
        {
            A[left++] = c[k];//
        }
}
void MergeS(int *b,int left,int right)//递归方式为从顶向下
{
    if(left==right)
        return;
    int mid = (left + right) / 2;
    MergeS(b, left, mid);
    MergeS(b, mid + 1, right);
    merge(b, left,mid, right);
}
void MergeN(int *b,int len)
{
    int left, mid, right;// 子数组索引,前一个为A[left...mid]，后一个子数组为A[mid+1...right]
    for (int i = 1; i < len; i *= 2)        // 子数组的大小i初始为1，每轮翻倍
    {
        left = 0;
        while (left + i < len)              // 后一个子数组存在(需要归并)
        {
            mid = left + i - 1;//因为要顾及后面数组不一定等于左边，所以mid不一定是中间数字
            right = mid + i < len ? mid + i : len - 1;// 后一个子数组大小可能不够
            merge(b, left,mid,right);
            left = right + 1;               // 前一个子数组索引向后移动
        }
}}
int main()
{
    init(a, maxsize, maxnum);
    MergeN(a,maxsize);
    show(a, maxsize);
}
