#include<stdio.h>
#include<stdlib.h>
#define maxsize 9
#define maxnum 30
int a[maxsize];
void init()
{
    for (int i = 0; i < maxsize;i++)
        a[i] = rand() % maxnum;
}
void print()
{
    for (int i = 0; i < maxsize;i++)
        printf("%d ", a[i]);
    puts("");
}
void fft(int *a,int left,int right)
{
    if(left>right)
        return;
    int i=left;
    int j = right;
    int key = a[i];
    int temp = 0;
    while(i<j)
    {
        while(a[j]>=key & i<j)
        {
            j--;
        }
        temp=a[i];//
        a[i] = a[j];
        a[j] = temp;
        while(a[i]<=key & i<j)
        {
            i++;
        }
        temp=a[i];//
        a[i] = a[j];
        a[j] = temp;
    }
    fft(a, left, i - 1);
    fft(a, j + 1, right);
}
int main()
{
    init();
    print();
    fft(a, 0, maxsize - 1);
    print();
    return 0;
}//每一趟的执行时间为n，一共要执行log2 n趟。