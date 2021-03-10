#include<stdio.h>
#define n 6
#define max 10000
float A[n][n];
int path[n][n];      /* 路径矩阵*/
float distance[n][n];
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
void Floyd( float A[ ][n],float dist[ ][n]) /* A路径长度矩阵, dist是G的带权邻接矩阵*/
    {    
        int i, j, k,pre;
        for (i=0; i<n; i++)              /* 设置A和path的初值*/ 
        for (j=0; j<n; j++)
        {  
            if (dist[i][j] !=max )  
            path[i][j]=i+1;   /* i是j的前趋*/
            else  
            path[i][j]=0;
            
            A[i][j]=dist[i][j];            
        }
        for (k=0; k<n; k++)            /* 以0, 1,…, n-1为中间顶点做n次*/
        for (i=0; i<n; i++)
        for (j=0; j<n; j++)
        if (A[i][j]>(A[i][k]+A[k][j]))
        {             
            A[i][j]=A[i][k]+A[k][j]; /* 修改路径长度*/
            path[i][j]=path[k][j];          /* 修改路径 */
        } 
        for (i=0; i<n; i++) /* 输出所有顶点对i,j之间最短路径的长度和路径*/
        for (j=0; j<n; j++)
        {    
            printf("%d->%d cost:%.0f  route:", i,j,A[i][j]);       
            pre=path[i][j]; 
            while((pre!=0)&&(pre!=i+1))
            {     
                printf("<%d", pre-1);                    
                pre=path[i][pre-1];  
            }
                 printf("<%d\n", i);
        }
    }
int main()
{
    input();
    Floyd(A, distance);
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