//一�?单链�?，可以实现生成，按�??几个查�?�的功能
#include<stdio.h>
#include<stdlib.h>
typedef struct Lnode{
    int data;
    struct Lnode *next;
} Link;
void init(Link* a)//生成链表
{
    int t;
    scanf("%d", &t);
    Link *last=a;
    while(t!=9999)
    {
        Link *new;
        new = (Link *)malloc(sizeof(Link));
        last->next = new;
        new->data = t;
        last = last->next;
        scanf("%d", &t);
    }
    //last->next = NULL;
    last->next = a;
}
void show(Link *b)//输出链表
{
    Link* a = b->next;
    while(a!=NULL)
    {
        printf("%d", a->data);
        a = a->next;
    }
    puts("");
}
int findn(Link *c,int num)//按照�?几个查�??
{
    Link *a = c->next;
    while(num>1 && a->next!=NULL)
    {
        num--;
        a =a->next;
    }
    if(num!=1)
    {
        printf("Pay attention to your input!!");
    }
    else{
        printf(" it is  %d", a->data);
        return a->data; 
    }
}
int finds(Link *d,int s)//按值查�?
{
    int i = 1;
    Link *a = d->next;
    while(a!=NULL)
    {
        if(a->data==s)
            printf("|%d:%d|",i,s);
        a = a->next;
        i++;
    }
}
int plugin(Link *e,int g,int x)//在x位置插入一�?值为g的数�?
{
    Link *a = e->next;
    if(x<=0)
        return 0;
    int i = 1;
    while(i!=x-1)
    {
        a = a->next;
        i++;
    }
    Link *new = (Link *)malloc(sizeof(Link));
    new->next = a->next;
    new->data = g;
    a->next = new;
    return 0;
}
int del(Link *b,int x)//删除某一�?位置的节�?
{
    Link *a = b->next;
    Link *dd;
    if(x<=0)
        return 0;
    int i = 1;
    while(i!=x-1)
    {
        a = a->next;
        i++;
    }
    dd = a->next;
    a->next = a->next->next;
    free(dd);
    return 0;
}
int main()
{
    Link*a = (Link *)malloc(sizeof(Link));
    init(a);
    show(a);
    del(a, 5);
    show(a);
    finds(a, 5);
    return 0;
}