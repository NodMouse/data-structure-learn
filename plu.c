#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 20
#define MAXS 10
bool sort(int *arr,int n)
{
    int temp=0;
    for(int i=0;i<n;i++)// i=3 j=0
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]<arr[i]);
            else             
            {
                temp=arr[i];
                for(int k=i;k>j;k--)
                {
                    arr[k]=arr[k-1];
                }
                arr[j]=temp;
            }
            
        }
    }
}
int main()
{
    int ar [MAXS];
    for(int i=0;i<MAXS;i++)
    {
        ar[i]=(rand()%MAX+1);
    }
    for(int i=0;i<MAXS;i++)
    {
        printf("%d ",ar[i]);
    }
    if(sort(ar,MAXS))
    printf("OK!\n");
    else
    {
        printf("ERROR!\n");
        exit(0);
    }
    for(int i=0;i<MAXS;i++)
    {
        printf("%d ",ar[i]);
    }
    return 0;    
}