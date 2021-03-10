#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 40
#define maxnum 40
int a[maxsize];
#include"swap.h"
void shell()
{
    /*int h = 0;
    while(h<=maxsize)
        h = 3 * h + 1;*/
        int h = maxsize / 2;
while(h>=1)
{
{
    for (int i = h; i < maxsize; i++)
    {
        int j = i - h;
        printf("h=%d|", h);
        int get = a[i];
        while(j>=0 &&a[j]>get)
        {
            a[j + h] = a[j];
            j = j - h;
        }
        a[j + h] = get;
        show(a, maxsize);
    }
    //h = (h - 1) / 3;
    h = (h-1)/ 2;
}
}
}
int main()
{
    init(a, maxsize,maxnum);
    shell();
    show(a, maxsize);
}