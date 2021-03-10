#include<stdio.h>
#include<stdlib.h>
#include"swap.h"
#define maxsize 30
#define maxnum 40
int a[maxsize];
void map()
{
    for (int i = 0; i < maxsize - 1;i++)
    {
        for (int j = 0; j < maxsize - i - 1;j++)
        {
            if(a[j+1]<a[j])
                swap(a, j, j + 1);
        }
    }
}
int main()
{
    init(a, maxsize, maxnum);
    map();
    show(a, maxsize);
    return 0;
}