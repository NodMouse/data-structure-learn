#include<stdio.h> //ʵ�ֹ�������㷨
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
/*  i,j,k,l�ֱ���Ҫ����Ķ���������������������������ʼ���յ��±�*/
{
    int  m=k;  
    bitree p;
    p = (bitree)malloc(sizeof(bitnode));             /* ��������*/
    p->data=preod[i]; 
    while ( inod[m] != preod[i] ) m++;                                      /* ���Ҹ���������������е�λ��*/
    if ( m==k )   //û��������        
    p->lchild = NULL;
    else      //����������
    p->lchild = BPI( preod, inod, i+1, i+m-k, k, m-1 );
    if ( m==l )      //û��������
    p->rchild=NULL;
    else  /* �����������й���*/
    p->rchild = BPI( preod, inod, i+m-k+1, j, m+1, l ); 
    return (p);
}
int main()
{
    char preod[200] = "ABCDEGF";
    char inod[200]="CBEGDFA"; /* �����������������д������*/
    bitree a = BPI(preod, inod, 0, 6, 0, 6);
    guangdu(a);
    return 0;
}
