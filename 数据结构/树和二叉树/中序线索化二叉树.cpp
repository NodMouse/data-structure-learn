#include<stdio.h> //ʵ����������㷨
#include<stdlib.h>
typedef struct BitNode{
    int ltag,rtag;
    char data;
    struct BitNode *lchild, *rchild;
} bitnode, *bitree;
int create_bitree(bitree *bt)//���򴴽�
{
    char data;
    scanf("%c", &data);
    getchar();
    if (data=='#') {
        *bt = NULL;
    } else {
        *bt = (bitree)malloc(sizeof(bitnode));
        if (!(*bt))
            exit(0);
        (*bt)->data = data;
        create_bitree(&(*bt)->lchild);
        create_bitree(&(*bt)->rchild);
    }
    return 1;
}
bitree pre;
void INTHREAD(bitree p)
{
    if (p!=NULL)
    { 
        INTHREAD(p->lchild);           /* ������������*/
        if (p->lchild==NULL)  p->ltag=1;       /* ������������־*/ 
        if (p->rchild==NULL)  p->rtag=1;     /* ������������־*/ 
        if (pre!=NULL)
        {  
            if (pre->rtag==1)          /* *pre��������*/
                pre->rchild=p;           /* ������pre->rchildָ��*p */ 
            if (p->ltag==1)               /* *p��������*/
                p->lchild=pre;          /* ������p->lchildΪpre */
        }
        pre=p;  
        INTHREAD(p->rchild);      /* ������������*/
    }
}
int main()
{
    bitree a;
    create_bitree(&a);
    INTHREAD(a);
}