#include<iostream>
using namespace std;
typedef struct list{
    int data;
    list *last;
    list *next;
} list;
void del(list &a, int pos);
void show(list &a);
void init(list &a);
void insert(list &a, int num, int pos);
void search(list &a, int dat);
int main()
{
    list *a;
    a = new (list);
    a->data = 0;
    a->last = NULL;
    a->next = NULL;
    init(*a);
    insert(*a, 50, 5);
    show(*a);
    cout << endl;
    //del(*a, 5);
    //show(*a);
    //cout << endl;
    search(*a, 50);
    return 0;
}
void init(list &a)
{
    int t;
    cin >> t;
    list *now=&a;
    while(t!=9999)
    {
        list * add;
        add = new (list);
        a.data++;
        add->data = t;
        add->last = now;
        add->next = NULL;
        now->next = add;
        now = now->next;
        cin >> t;
    }
}
void show(list &a)
{
    list *b = a.next;
    while(b!=NULL)
    {

        cout << b->data << " ";
        b = b->next;
    }
}
void insert(list &a,int num,int pos)
{
    int i = 0;
    list *now=&a;
    list *newl;
    newl = new (list);
    newl->data = num;
    while(i!=pos-1)
    {
        i++;
        now = now->next;
    }
    newl->last = now;
    newl->next = now->next;
    now->next->last = newl;
    now->next = newl;
    a.data++;
}
void del(list &a,int pos)
{
    int now = 0;
    list *b = &a;
    list *temp;
    while(now!=pos-1)
    {
        b = b->next;
        now++;
    }
    temp = b->next;
    b->next->next->last = b;
    b->next = b->next->next;
    free(temp);
}
void search(list &a, int dat)
{
    list *b = a.next;
    for (int i = 1; i < a.data;i++)
    {
        if(b->data==dat)
        {
            cout << "|" << i << ":"<< dat<<"|";
        }
        b = b->next;
    }
}