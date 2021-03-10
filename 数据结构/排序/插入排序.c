#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 40
#define maxnum 40
int a[maxsize];
#include"swap.h"
void insrt()
{
    for (int i = 1; i < maxsize;i++)
    {
        int pos = i - 1;
        int key = a[i];
        while(pos>=0 && a[pos]>key)
        {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos+1] = key;

    }
}
int main()
{
    init(a, maxsize, maxnum);
    insrt();
    show(a, maxsize);
}