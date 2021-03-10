#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"swap.h"
#define maxsize 40
#define maxnum 30
int A[maxsize];
void merge(int *a,int left,int mid,int right)
{
    int len = right - left + 1;
    int G[len];
    int temp=0;
    int i = left;
    int j = mid+1;//
    while(i<=mid && j<=right)
    {
        G[temp++] = a[i] > a[j] ? a[j++] : a[i++];
    }
    while(i<=mid)
    {
        G[temp++] = a[i++];
    }
    while(j<=right)
    {
        G[temp++] = a[j++];
    }
    for (int k = 0; k < len;k++)
    {
        a[left++] = G[k];//
    }
}
void mergeD(int *a,int left,int right)//所有递归必须有结束条件
{
    if(left==right)
        return;
    int mid = (left + right) / 2;
    mergeD(A, left, mid);
    mergeD(A, mid + 1, right);
    merge(A, left, mid, right);
}
void mergeN(int *a,int len)//不熟悉
{
    int left, mid, right;
    for (int i = 1; i < len;i*=2)
    {
        left = 0;
        while(left+i<len) 
        {
            mid = left + i-1;
            if(left+2*i>len)
            {
                right = len - 1;
            }
            else
                right = mid + i;
            merge(A, left, mid, right);
            left =right+1;
        }
    }
}
int main()
{
    init(A, maxsize, maxnum);
    mergeN(A,maxsize);
    show(A, maxsize);

}