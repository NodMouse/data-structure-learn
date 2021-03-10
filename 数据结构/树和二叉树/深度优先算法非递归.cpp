#include<stdio.h> //实现深度优先算法 需要用到栈
/*
1.当p所指的结点非空时将该节点存储地址进栈，然后p指向孩子结点
2.当p所指结点空时候，从栈顶退出栈顶元素送p并访问，然后将p指向另一个孩子结点
3.反复直到p为空栈顶指针top=-1
*/
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
int preorder(bitree &bt)
{
    int top = -1;
    bitree stack[200];
    bitree now=bt;
    while((now!=NULL) || (top!=-1))
    {
        if(now){ //先遍历左孩子，并输出。
            printf("%c", now->data);
            top++;
            stack[top] = now;
            now = now->lchild;
        }
        else
        //当左孩子遍历完后，取栈顶，找右孩子。此时循环还没有结束，再遍历它的左孩子，直至孩子全部遍历结束。
        {
            now = stack[top];
            top--;
            now = now->rchild;
        }
    }
    return 1;
}
int midorder(bitree &bt)
{
    int top = -1;
    bitree stack[200];
    bitree now=bt;
    while((now!=NULL) || (top!=-1))
    {
        if(now){
            top++;
            stack[top] = now;
            now = now->lchild;
        }
        else
        {
            now = stack[top];
            top--;
            printf("%c", now->data);
            now = now->rchild;
        }
    }
    return 1;
}
int lastorder(bitree &bt)//问题是每个根会被遍历两次
{
    int top = -1;
    bitree stack[200];
    bitree now=bt,prior=NULL;
    while((now!=NULL) || (top!=-1))
    {
        if(now){
            top++;
            stack[top] = now;
            now = now->lchild;
        }
        else
        {
            now = stack[top];
            if(now->rchild && now->rchild!=prior)//要输出根节点之前应该输出的一个节点是右节点,若右节点不为空 并且 右节点 不等于r（前一个访问的节点）
                now = now->rchild;
                else{
                    top--;
                    printf("%c", now->data);
                    prior = now;
                    now = NULL;
                }
        }
    }
    return 1;
}
int main()
{
    bitree a;
    create_bitree(&a);
    preorder(a);
    puts(":preorder");
    midorder(a);
    puts(":midorder");
    lastorder(a);
    printf(":lastorder");
    return 0;
}
