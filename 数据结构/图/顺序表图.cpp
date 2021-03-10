#include<stdio.h>
#include<stdlib.h>
#define  n  5   /*图的顶点数*/ 
typedef  struct{  
    char  vexs[n];        /* 顶点数组 */ 
    double  arcs[n][n];       /* 邻接矩阵*/
} graph;
graph a;
void createwxt(graph &a) //时间复杂度O(n*n)
{
    int i, j;
    char temp;
    double weight=0;
    for (i = 0; i < n;i++)
        for (j = 0; j < n;j++)
            a.arcs[i][j] = 0;//邻接矩阵初始化
    for (i = 0; i < n; i++)//填入顶点数据值
    {
        scanf("%c", &temp);
        getchar();
        a.vexs[i] = temp;
    }
    scanf("%d %d %lf", &i, &j, &weight);
    while(weight!=9999)//判断是否继续填入
    {
        a.arcs[i][j] = weight;
        a.arcs[j][i] = weight;
        scanf("%d %d %lf", &i, &j, &weight);
    }
}
int visited[n]={0};//存储 是否遍历过
void shendu(int i) //从i出发深度遍历图
{
    int j;
    printf("node:%c \n", a.vexs[i]);//输出当前结点
    visited[i] = 1; //经过当前结点标志位设置1
    for (j = 0; j < n;j++) //依次搜索i的邻接点
    {
        if((a.arcs[i][j]==1)&&(visited[j]==0))// 找到往后的链接的结点
            shendu(j);
    }
}
int visitedg[n]={0};//存储 是否遍历过
int qeeue[n] = {0};
void guangdu(int k)//时间复杂度 n*n 空间复杂度n
{
    int i, j;
    int head = 0;
    int tail = 0;
    printf("node:%c \n", a.vexs[k]);//输出当前结点
    visitedg[k] = 1;
    qeeue[tail++] = k;//k顶点入队
    while(head!=tail)//当队列不为空的时候循环
    {
        i = qeeue[head--];//取出队列头的数据
        for (j = 0; j < n;j++)//循环找与i相链接的结点
        {
            if((a.arcs[i][j]==1)&&(visitedg[j]!=1)) //如果找到了与i相链接没有遍历的结点
            {
                printf("node:%c \n", a.vexs[j]);//输出当前结点
                visitedg[j] = 1;
                qeeue[tail++] = j;//j入队
            }
        }
    }
}
void prim(int i)
{

}
int main()
{
    createwxt(a);
    shendu(0);
    return 0;
}