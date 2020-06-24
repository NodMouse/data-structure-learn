#include"stdio.h"
#include"stdlib.h"
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
    cost[i][j]=MAXCOST; //联通不到的权为无限大 已经联通过的设置为0
    }
    for(int k=1;k<=s;k++)
    {
        scanf("%d %d %d",&a,&b,&c); //把节点和权联通情况存储到数组中
        cost[a][b]=c;
        cost[b][a]=c;
    }
    printf("Totally sum:%d",kruskal(cost,n));//输出费用总数
    return 0;
}
int kruskal(int (*cost)[MAX],int n)
{
    int source[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        source[i]=i; //0 1 2
    }
    for(int g=0;g<n-1;g++)
    {
        int x,y;
        int min=MAXCOST;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(cost[i][j]<min && cost[i][j] && source[i]!=source[j])
                {
                    min=cost[i][j];
                    x=i;
                    y=j;
                }
            }
        }
        printf("%d->%d cost:%d\n",x,y,cost[x][y]);
        sum+=cost[x][y];
        cost[x][y]=0;
        cost[y][x]=0;
        if(x<y)
        {
            source[y]=source[x];
        }
        else
        {
            source[x]=source[y];
        }
        
    }
    return sum;
}