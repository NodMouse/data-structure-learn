#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 30
#define maxnum 40
int a[maxsize];
#include"swap.h"
int maxify(int *A,int a,int b,int c)
{
    int max;
    max = A[a] > A[b] ? a : b;
    max = A[max] > A[c] ? max : c;
    return max;
}
void heapify(int *a,int i,int size)//a为数组，i为堆顶，size为堆大小
{
    int lchild = 2 * i + 1;
    int rchild = 2 * i + 2;
    int max = i;
    max = maxify(a,i, lchild, rchild);
    if(max!=i && lchild<size && rchild<size)//注意是否超界
    {
        swap(a, i, max);
        heapify(a, max, size);
    }
}
int bulidheap(int *a,int n)
{
    int heapsize = n;
    for (int i = heapsize / 2 - 1; i >= 0;i--)
    {
        heapify(a, i, heapsize);
    }
    return heapsize;
}
void sort(int *a,int n)
{
    int heaps = bulidheap(a, n);
    while(heaps>1)
    {
        heaps--;
        swap(a, 0, heaps);
        heapify(a, 0, heaps);
    }
}
int main()
{
    init(a, maxsize, maxnum);//
    sort(a, maxsize);
    show(a, maxsize);
}