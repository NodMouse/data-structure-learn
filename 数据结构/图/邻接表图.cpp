#include<stdio.h>
#include<stdlib.h>
#define  n  4   /*ͼ�Ķ�����*/
typedef   struct   node   //�����ڽ�����
{
    int  node;   //����뵱ǰ����ڽӵĶ�������
    struct node     *next;          /* ���� */
}edgenode;
typedef struct //����
{
    char     data;      //��Ŷ����Լ���������Ϣ
    edgenode  *link;    //��������ڸö���ı�����ɵĵ������ͷ���λ��
} vexnode;
vexnode a[4];
vexnode ga[n];    /* ����� */
void createlist(vexnode (&a)[n])//����ͼ
{
    int i, j;
    char temp;
    edgenode *s;
    for (i = 0; i < n; i++)//����ÿ�����������
    {
        scanf("%c", &temp);
        getchar();
        a[i].data = temp;
    }
    scanf("%d %d\n", &i, &j);//������һ��ijֵ
    while(i!=9999 || j!=9999) //�ж��Ƿ��Ѿ���������
    {
        s = (edgenode *)malloc(sizeof(edgenode));//�����ڽӵ����Ϊj�ı߱���s
        s->node = j;
        s->next = a[i].link;
        a[i].link = s;   //��s���붥��i�ı߱�ͷ��
        s = (edgenode *)malloc(sizeof(edgenode));  //�����ڽӵ����Ϊi�ı߱���s
        s->node = i;
        s->next = a[j].link;
        a[j].link = s;//��s����j�ı߱�ͷ��
        scanf("%d %d\n", &i, &j);        
    }
}
int visited[n]={0};
void shendu(int i)//��i��������������� ��������ͼ
{
    edgenode *p;
    printf("node:%c \n", ga[i].data); //���ʵ�ǰ����
    visited[i] = 1;
    p = ga[i].link;//ȡi�ı߱�ͷָ��
    while(p!=NULL)
    {
        if(visited[p->node]==0)//�����߱�ͷָ���ҵ�û�б�������
            shendu(p->node);
        p = p->next;
    }
}
int visitedg[n]={0};
int qeeue[n] = {0};
void guangdu(int k)//ʱ�临�Ӷ�O(2e+n)�ռ临�Ӷ�o(n)
{
    int i;
    edgenode *p;
    int head = 0;
    int tail = 0;
    printf("node:%c \n", ga[k].data);//�����ǰ���
    qeeue[tail++] = k;//k�������
    visitedg[k] = 1;
    while(head!=tail)
    {
        i = qeeue[head--];
        p = ga[i].link;
        while(p!=NULL)
        {
            if(visitedg[p->node]!=1)
            {
                printf("%c \n", ga[p->node].data);
                visitedg[p->node] = 1;
                qeeue[tail++] = p->node;//k�������
            }
            p = p->next;
        }
    }

}
int main()
{
    createlist(a);
}