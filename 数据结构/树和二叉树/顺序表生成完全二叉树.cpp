#include<stdio.h> //最好用于完全二叉树
#define MAX_SIZE 200
typedef int ElemType;
typedef struct stree
{
    ElemType bitTree[MAX_SIZE];
    int pointer;   //存放表中最后一个数据
}STree;
//init
void STree_Init(STree &T)
{
    for(int i=0;i<MAX_SIZE;++i)
        T.bitTree[i]=9999;
    T.pointer=0;
}
void Strget(STree &T)
{
    int i = 0;
    int now = 0;
    while(i!=10000)
    {
        T.bitTree[now++] = i;
        scanf("%d", &i);
    }
    T.pointer = now;
}
int main()
{
    STree bt;
    STree_Init(bt);
    Strget(bt);
    for (int i = 1; i < bt.pointer;i++)
    {
        if(bt.bitTree[i]==9999)
            printf("@ ");
        else
         printf("%d ", bt.bitTree[i]);
    }
    return 0;
}