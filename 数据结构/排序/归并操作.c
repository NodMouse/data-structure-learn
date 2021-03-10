//归并排序的时间复杂度为nlog2n 所需空间为n   稳定
#include<stdio.h>
#include<stdlib.h>
int g[10]={1,3,5,6,9,2,4,6,8,12};
void show(int *a,int max)
{
    for (int yyyyyy=0; yyyyyy < max;yyyyyy++)
    {
        printf("%d ", a[yyyyyy]);
    }
    puts("");
}
void merge(int *a,int left,int mid,int right)
{
    int len = right - left + 1;
    int b[len];
    int temp=0;
    int i = left;
    int j = mid + 1;
    while(i<=mid && j<=right)
    {
        if(a[i]>a[j])
        {
            b[temp] = a[j];
            j++;
        }
        else
        {
            b[temp] = a[i];
            i++;
        }
        temp++;
    }
    while(i<=mid)
    {
        b[temp++] = a[i++];
    }
    while(j<=right)
    {
        b[temp++] = a[j++];
    }
    while(temp-->=0)
    {
        a[temp] = b[temp];
    }
}
int main()
{
    merge(g, 0, 4, 9);
    show(g, 10);
}