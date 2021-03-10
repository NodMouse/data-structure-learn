#include<stdio.h>
#define n 6
float D[n];//d是源节点到其他地方的目前最小值
int p[n], s[n];//p存放前驱信息 s标记是否已经计算过
#define max 10000
float distance[8][8];
void input()
{
    puts("Tell me how much sides do you have ?");   // s储存边数量
    int s;
    int a,b,c;
    scanf("%d",&s);
    puts("Now tell me your datas exp:1 2 5"); 
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
    distance[i][j]=max; //联通不到的权为无限大
    }
    for(int k=0;k<s;k++)
    {
        scanf("%d %d %d",&a,&b,&c); //把节点和权联通情况存储到数组中
        distance[a][b]=c;
    }
}
void Dijkstra (int v, float dist[8][8]) /* dist为有向图的带权邻接矩阵*/
    {
        int i, j, k, v1, min; //v1是源结点
        v1=v;
        for( i=0; i<n; i++)               /* 各数组进行初始化*/
        {  
            D[i]=dist[v1][i];
            if( D[i] != max )  
                p[i]= v1+1;   //源头设为自己
            else 
                p[i]=0; 
            s[i]=0;  
        }
        s[v1]=1;                   /* 将源点送U */
        for( i=0; i<n; i++)          /* 求源点到其余顶点的最短距离*/
        {  
            min=10001;
            for( j=0; j<n;j++)
            if ( ( !s[j] )&&(D[j]<min) )      /* 找出到源点具有最短距离的边*/
            {
                min=D[j]; 
                k=j;  
            }
            s[k]=1;                   /* 将找到的顶点k送入U */ 
            for (j=0; j<n; j++)
            if ( (!s[j])&&(D[j]>D[k]+dist[k][j]) )    /* 调整V-U中各顶点的距离值*/
            {
                D[j]=D[k]+dist[k][j];
                p[j]=k+1; 
            } /* k是j的前趋 */
        }
    }
int main()
{
    input();
    Dijkstra(5, distance);
}
/*example
12
1 5 10
5 1 5
5 0 24
5 3 25
1 0 18
0 1 6
1 2 7
2 0 9
0 3 8
3 2 12
2 3 15
4 2 4
*/