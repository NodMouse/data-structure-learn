#include<stdio.h> //实现广度优先算法
#include<stdlib.h>
typedef struct BitNode{
    char data;
    struct BitNode *lchild, *rchild;
} bitnode, *bitree;
void guangdu(bitree bt)
{
    bitree now = bt;
    bitree qeeue[200];
    int tail = 0;
    int front = 0;
    if(now)
    {
        qeeue[front] = now;
        tail++;
    }
    while(front<tail)
    {
        now = qeeue[front];
        front++;
        printf("%c", now->data);
        if(now->lchild!=NULL)
        {
            qeeue[tail++] = now->lchild;
        }
        if(now->rchild!=NULL)
        {
            qeeue[tail++] = now->rchild;
        }
    }
}
bitree BPI(char preod[ ],char inod[ ],int i,int j,int k,int l)
/*  i,j,k,l分别是要构造的二叉树的先序和中序序列数组的起始和终点下标*/
{
    int  m=k;  
    bitree p;
    p = (bitree)malloc(sizeof(bitnode));             /* 构造根结点*/
    p->data=preod[i]; 
    while ( inod[m] != preod[i] ) m++;                                      /* 查找根结点在中序序列中的位置*/
    if ( m==k )   //没有左子树        
    p->lchild = NULL;
    else      //构造左子树
    p->lchild = BPI( preod, inod, i+1, i+m-k, k, m-1 );
    if ( m==l )      //没有右子树
    p->rchild=NULL;
    else  /* 对右子树进行构造*/
    p->rchild = BPI( preod, inod, i+m-k+1, j, m+1, l ); 
    return (p);
}
int main()
{
    char preod[200] = "ABCDEGF";
    char inod[200]="CBEGDFA"; /* 设置先序与中序序列存放数组*/
    bitree a = BPI(preod, inod, 0, 6, 0, 6);
    guangdu(a);
    return 0;
}
