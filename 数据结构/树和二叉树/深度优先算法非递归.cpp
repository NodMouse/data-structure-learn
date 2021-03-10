#include<stdio.h> //ʵ����������㷨 ��Ҫ�õ�ջ
/*
1.��p��ָ�Ľ��ǿ�ʱ���ýڵ�洢��ַ��ջ��Ȼ��pָ���ӽ��
2.��p��ָ����ʱ�򣬴�ջ���˳�ջ��Ԫ����p�����ʣ�Ȼ��pָ����һ�����ӽ��
3.����ֱ��pΪ��ջ��ָ��top=-1
*/
#include<stdlib.h>
typedef struct BitNode{
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
int preorder(bitree &bt)
{
    int top = -1;
    bitree stack[200];
    bitree now=bt;
    while((now!=NULL) || (top!=-1))
    {
        if(now){ //�ȱ������ӣ��������
            printf("%c", now->data);
            top++;
            stack[top] = now;
            now = now->lchild;
        }
        else
        //�����ӱ������ȡջ�������Һ��ӡ���ʱѭ����û�н������ٱ����������ӣ�ֱ������ȫ������������
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
int lastorder(bitree &bt)//������ÿ�����ᱻ��������
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
            if(now->rchild && now->rchild!=prior)//Ҫ������ڵ�֮ǰӦ�������һ���ڵ����ҽڵ�,���ҽڵ㲻Ϊ�� ���� �ҽڵ� ������r��ǰһ�����ʵĽڵ㣩
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
