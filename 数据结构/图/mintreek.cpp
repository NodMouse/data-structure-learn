#include<stdio.h>
#include<stdlib.h>
#define n 20  //最大的节点数量
#define e 50
#define MAXCOST 9999 //9999表示不连通
typedef struct{
    int fromvex, endvex;//边的起点和终点
    int weight;//边的权值
    int sign;//这个边是否已经被访问过
} edge;
edge T[e];// e为图中的边的数量
int G[n];//判断该边的两个顶点是否在同一个分量上的数组 分量数组
void kruskal(int N,int E)
{
    int i, j, fromv, endv, minedgeid, min, igtmp;
    for (i = 0; i <= N-1;i++)//数组设置初值 每一个结点的根节点都是自己
        G[i] = i;
    for (i = 0; i <= E - 1;i++)//输入边信息 左右和权重，并且设置访问次数为0
    {
        scanf("%d %d %d", &T[i].fromvex, &T[i].endvex, &T[i].weight);
        T[i].sign = 0;
    }
    j = 0;
    while(j<N-1) //循环n-1次可以连接n个结点
    {
        min = MAXCOST;//设置min的初值为9999
        for (i = 0; i <= E - 1;i++)//循环遍历所有的边
            if(T[i].sign==0)//只看没有被访问过的边
                if(T[i].weight<min) 
                {
                    min = T[i].weight;
                    minedgeid = i;
                    fromv = T[i].fromvex;
                    endv = T[i].endvex;
                }//将目前权值最小的边的边序号 左值 右值记录下来
        T[minedgeid].sign = 1;//设置当前边的标志位为已经访问过
        if(G[fromv]==G[endv])//如果在同一个分量上 则说明连接这两个结点是毫无意义的 
        ;//什么也不做，下次会跳过这条边
            else{//如果不在同一个分量上
                printf("%d->%d\n", fromv, endv); // 连接这条边
                j++; //循环次数减一
                igtmp = G[endv];//记录下来右边的值
                for (i = 0; i < N; i++) //将这个边左右两边所连接的子树合一
                    if (G[i] == igtmp)//找到所有右侧连接的结点
                        G[i] = G[fromv];//将右侧连接的结点的同一分量数组变成左侧的值
                }
    }
}
int main()
{
    puts("Tell me how much node and sides do you have ?");
    int a;   // n储存节点数量 s储存边数量
    int b;
    scanf("%d %d",&a,&b);
    kruskal(a, b);
}
/* example :
0 2 1
0 3 5
0 1 6
1 4 3
4 2 6
1 2 5
3 2 5
2 5 4
3 5 2
*/