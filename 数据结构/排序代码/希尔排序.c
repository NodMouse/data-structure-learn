#include<stdio.h>
#include<stdlib.h>
#include"swap.h"
#define maxsize 30
#define maxnum 40
int a[maxsize];
void shell()
{
    int h = maxsize / 2;
    while(h>=1)
    {
        for (int i = h; i < maxsize;i++)
        {
            int j = i-h;
            int get = a[i];
            while(j>=0 && a[j]>get)//插入排序
            {
                a[j + h] = a[j];
                j =j-h;
            }
            a[j + h] = get;
        }
        h = (h-1)/ 2;
    }
}
int main()
{
    init(a, maxsize, maxnum);
    shell();
    show(a, maxsize);
    return 0;
}