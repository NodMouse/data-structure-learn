#include<stdio.h>
#define n 6
float D[n];//d��Դ�ڵ㵽�����ط���Ŀǰ��Сֵ
int p[n], s[n];//p���ǰ����Ϣ s����Ƿ��Ѿ������
#define max 10000
float distance[8][8];
void input()
{
    puts("Tell me how much sides do you have ?");   // s���������
    int s;
    int a,b,c;
    scanf("%d",&s);
    puts("Now tell me your datas exp:1 2 5"); 
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
    distance[i][j]=max; //��ͨ������ȨΪ���޴�
    }
    for(int k=0;k<s;k++)
    {
        scanf("%d %d %d",&a,&b,&c); //�ѽڵ��Ȩ��ͨ����洢��������
        distance[a][b]=c;
    }
}
void Dijkstra (int v, float dist[8][8]) /* distΪ����ͼ�Ĵ�Ȩ�ڽӾ���*/
    {
        int i, j, k, v1, min; //v1��Դ���
        v1=v;
        for( i=0; i<n; i++)               /* ��������г�ʼ��*/
        {  
            D[i]=dist[v1][i];
            if( D[i] != max )  
                p[i]= v1+1;   //Դͷ��Ϊ�Լ�
            else 
                p[i]=0; 
            s[i]=0;  
        }
        s[v1]=1;                   /* ��Դ����U */
        for( i=0; i<n; i++)          /* ��Դ�㵽���ඥ�����̾���*/
        {  
            min=10001;
            for( j=0; j<n;j++)
            if ( ( !s[j] )&&(D[j]<min) )      /* �ҳ���Դ�������̾���ı�*/
            {
                min=D[j]; 
                k=j;  
            }
            s[k]=1;                   /* ���ҵ��Ķ���k����U */ 
            for (j=0; j<n; j++)
            if ( (!s[j])&&(D[j]>D[k]+dist[k][j]) )    /* ����V-U�и�����ľ���ֵ*/
            {
                D[j]=D[k]+dist[k][j];
                p[j]=k+1; 
            } /* k��j��ǰ�� */
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