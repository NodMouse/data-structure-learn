#include<stdio.h> //实现深度优先算法
#include<stdlib.h>
typedef struct BitNode{
    int ltag,rtag;
    char data;
    struct BitNode *lchild, *rchild;
} bitnode, *bitree;
int create_bitree(bitree *bt)//先序创建
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
        INTHREAD(p->lchild);           /* 左子树线索化*/
        if (p->lchild==NULL)  p->ltag=1;       /* 建立左线索标志*/ 
        if (p->rchild==NULL)  p->rtag=1;     /* 建立右线索标志*/ 
        if (pre!=NULL)
        {  
            if (pre->rtag==1)          /* *pre无右子树*/
                pre->rchild=p;           /* 右线索pre->rchild指向*p */ 
            if (p->ltag==1)               /* *p无左子树*/
                p->lchild=pre;          /* 左线索p->lchild为pre */
        }
        pre=p;  
        INTHREAD(p->rchild);      /* 右子树线索化*/
    }
}
int main()
{
    bitree a;
    create_bitree(&a);
    INTHREAD(a);
}