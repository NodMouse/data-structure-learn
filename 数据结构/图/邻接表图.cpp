#include<stdio.h>
#include<stdlib.h>
#define  n  4   /*图的顶点数*/
typedef   struct   node   //创建邻接链表
{
    int  node;   //存放与当前结点邻接的顶点的序号
    struct node     *next;          /* 链域 */
}edgenode;
typedef struct //顶点
{
    char     data;      //存放顶点自己的数据信息
    edgenode  *link;    //存放依附于该顶点的边所组成的单链表表头结点位置
} vexnode;
vexnode a[4];
vexnode ga[n];    /* 顶点表 */
void createlist(vexnode (&a)[n])//无向图
{
    int i, j;
    char temp;
    edgenode *s;
    for (i = 0; i < n; i++)//填入每个顶点的数据
    {
        scanf("%c", &temp);
        getchar();
        a[i].data = temp;
    }
    scanf("%d %d\n", &i, &j);//先输入一个ij值
    while(i!=9999 || j!=9999) //判断是否已经输入完了
    {
        s = (edgenode *)malloc(sizeof(edgenode));//生成邻接点序号为j的边表结点s
        s->node = j;
        s->next = a[i].link;
        a[i].link = s;   //将s插入顶点i的边表头部
        s = (edgenode *)malloc(sizeof(edgenode));  //生成邻接点序号为i的边表结点s
        s->node = i;
        s->next = a[j].link;
        a[j].link = s;//将s插入j的边表头部
        scanf("%d %d\n", &i, &j);        
    }
}
int visited[n]={0};
void shendu(int i)//从i出发遍历深度优先 搜索遍历图
{
    edgenode *p;
    printf("node:%c \n", ga[i].data); //访问当前顶点
    visited[i] = 1;
    p = ga[i].link;//取i的边表头指针
    while(p!=NULL)
    {
        if(visited[p->node]==0)//搜索边表头指针找到没有遍历到的
            shendu(p->node);
        p = p->next;
    }
}
int visitedg[n]={0};
int qeeue[n] = {0};
void guangdu(int k)//时间复杂度O(2e+n)空间复杂度o(n)
{
    int i;
    edgenode *p;
    int head = 0;
    int tail = 0;
    printf("node:%c \n", ga[k].data);//输出当前结点
    qeeue[tail++] = k;//k顶点入队
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
                qeeue[tail++] = p->node;//k顶点入队
            }
            p = p->next;
        }
    }

}
int main()
{
    createlist(a);
}