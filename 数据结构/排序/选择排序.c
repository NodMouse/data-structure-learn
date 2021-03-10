#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define maxsize 666
#define maxnum 40
#include"swap.h"
int a[maxsize];
void cho()
{
    int temp = 0;
    int s = 0;
    for (int i = 0; i < maxsize - 1;i++)
    {
        for (int j = 0; j <= maxsize - i - 1;j++)
        {
            if(temp<a[j])
            {
                temp = a[j];
                s = j;
            }
        }
        swap(a, maxsize-i-1, s);
        s = 0;
        temp = 0;
    }
}
int main()
{
    int begin, end;
    begin = clock();
    for (int g = 0; g < 100000;g++)
    {
    init(a, maxsize, maxnum);
    cho();
    }
    end = clock();
    printf("time=%d\n", end - begin);
    return 0;
}