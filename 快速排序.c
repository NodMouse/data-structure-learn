#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Mlength 20
#define Mvalue 11
int ggggg=1;
void ffp(int *a,int left,int right)
{
    if(left>=right)
    return;
    int i=left;
    int j=right;
    int key=a[left];
    int temp=0;
    while(i<j)
    {
        while(a[j]>=key && i<j)
        j--;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        while(a[i]<=key && i<j)
            i++;
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
    // ggggg++;
    //if(ggggg%2==1)
   // {
    for(int as=0;as<=Mlength-2;as++)
    {
        printf("%d->",a[as]);
    }
    printf("%d\n",a[Mlength-1]);//}
    //printf("mid:%d   ",left);*/
    ffp(a,left,i-1);
    ffp(a,i+1,right);
}
int main()
{
    int a[Mlength];
    for(int i=0;i<=Mlength-1;i++)
    {
        a[i]=(rand()%Mvalue+1);
        printf("%d ",a[i]);
    }
    puts("\nInit Ok");
    ffp(a,0,Mlength-1);
    for(int as=0;as<=Mlength-1;as++)
    {
        printf("%d ",a[as]);
    }
}
