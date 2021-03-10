#include<stdio.h> //实现深度优先算法
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
int visit(char e)
{
    printf("%c", e);
    return 0;
}
void preorder(bitree bt)
{
    if (bt) {
        visit(bt->data);
        preorder(bt->lchild);
        preorder(bt->rchild);
    }
}
void midorder(bitree bt)
{
    if (bt) {
        midorder(bt->lchild);
        visit(bt->data);
        midorder(bt->rchild);
    }
}
void lastorder(bitree bt)
{
    if (bt) {
        lastorder(bt->lchild);
        lastorder(bt->rchild);
        visit(bt->data);
    }
}
int get_tree_depth(bitree bt)
{
    int ldepth, rdepth;

    if (!bt)
        return 0;
    else if (!bt->lchild && !bt->rchild)
        return 1;
    else {
        ldepth = get_tree_depth(bt->lchild);
        rdepth = get_tree_depth(bt->rchild);

        return (ldepth > rdepth ? ldepth : rdepth) + 1;
    }
}
int get_num_of_leave(bitree bt)
{
    if (!bt)
        return 0;
    else if (!bt->lchild && !bt->rchild)
        return 1;
    else
        return (get_num_of_leave(bt->lchild) + get_num_of_leave(bt->rchild));
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