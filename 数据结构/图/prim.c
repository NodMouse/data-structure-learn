//copyright 电子信息工程170502韩磊
#include<stdio.h>
#include<stdlib.h>
#define MAX 100  //最大的节点数量
#define MAXCOST 9999 //9999表示不连通
int cost[MAX][MAX]; //[a][b]表示从a到b的权
int prim(int (*cost)[MAX],int n);
int main()
{
    puts("Tell me how much node and sides do you have ?");
    int n;   // n储存节点数量 s储存边数量
    int s;
    int a,b,c;
    scanf("%d %d",&n,&s);
    puts("Now tell me your datas exp:1 2 5"); 
    for(int i=1;i<=n;i++)
    {
    for(int j=1;j<=n;j++)
    cost[i][j]=MAXCOST; //联通不到的权为无限大
    }
    for(int k=1;k<=s;k++)
    {
        scanf("%d %d %d",&a,&b,&c); //把节点和权联通情况存储到数组中
        cost[a][b]=c;
        cost[b][a]=c;
    }
    prim(cost, n); //输出费用总数
    return 0;
}
int prim(int (*cost)[MAX],int n)
{
   int mincost[MAX]; //mincost代表当前已经生成的树中到所有点权最小的距离  如mincost[2]为3 表示当前已经存在的树中没有第二个节点而且最近的权是3   当值为0表示已经加入到树中
   int seted[MAX]; //seted表示当前节点是否加入到树中 属于标记符号
   int source[MAX]; //source[i]表示弟i个节点是由谁带入树中的  
   int sum=0;//sum表示总数
   for(int i=1;i<=n;i++)//给第一次循环赋值（第一次循环 节点1已经在树中）
   {
       mincost[i]=cost[1][i]; //把所有1能连接到的节点加入到最小距离中 
       seted[i]=0;//把所有节点设置为还没有加入树
       source[i]=1;//把所有节点的默认源设置为1
   }
   seted[1]=1;//1号节点加入树中
    for(int j=2;j<=n;j++)//这个循环每次往树中加入一个节点
    {
        int min=MAXCOST; //min用来存储当前能连接的所有节点中权最小的一个
        int minid=0;//minid 用来存储当前最近节点min的所连接的节点是哪一个
        for(int k=2;k<=n;k++)//这个循环用来寻找最小的min 和其节点
        {
            if(mincost[k]<min && seted[k]==0 )//如果当前搜索的节点比之前节点小并且还没加入树中则设置min为当前节点
            {
                min=mincost[k];
                minid=k;
            }
        }
        printf("%d->%d cost:%d\n",source[minid],minid,min);//当前树连接到节点 并且输出费用
        seted[minid]=1;//把最近节点设置为已加入树中
        sum=sum+min;//计算总费用
        for(int g=2;g<=n;g++) //下一次循环用来更新，因为有新的节点加入树则最近数组将会发生变化
        {
            if(seted[g]==0 && mincost[g]>cost[minid][g])//找出加入之后节点比加入之前近的
            {
                mincost[g]=cost[minid][g];//改变最小距离的
                source[g]=minid;//将最近的那个节点的源头记录下来方便下次循环用
            }
        }
    }
    return sum; // 返回费用总数
}