#include<stdio.h> //实现广度优先算法
#include<stdlib.h>
typedef struct BitNode{
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
int main()
{
    bitree a;
    create_bitree(&a);
    guangdu(a);
    return 0;
}
