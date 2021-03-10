#include<stdio.h>
#include<stdlib.h>
#define  n  5   /*ͼ�Ķ�����*/ 
typedef  struct{  
    char  vexs[n];        /* �������� */ 
    double  arcs[n][n];       /* �ڽӾ���*/
} graph;
graph a;
void createwxt(graph &a) //ʱ�临�Ӷ�O(n*n)
{
    int i, j;
    char temp;
    double weight=0;
    for (i = 0; i < n;i++)
        for (j = 0; j < n;j++)
            a.arcs[i][j] = 0;//�ڽӾ����ʼ��
    for (i = 0; i < n; i++)//���붥������ֵ
    {
        scanf("%c", &temp);
        getchar();
        a.vexs[i] = temp;
    }
    scanf("%d %d %lf", &i, &j, &weight);
    while(weight!=9999)//�ж��Ƿ��������
    {
        a.arcs[i][j] = weight;
        a.arcs[j][i] = weight;
        scanf("%d %d %lf", &i, &j, &weight);
    }
}
int visited[n]={0};//�洢 �Ƿ������
void shendu(int i) //��i������ȱ���ͼ
{
    int j;
    printf("node:%c \n", a.vexs[i]);//�����ǰ���
    visited[i] = 1; //������ǰ����־λ����1
    for (j = 0; j < n;j++) //��������i���ڽӵ�
    {
        if((a.arcs[i][j]==1)&&(visited[j]==0))// �ҵ���������ӵĽ��
            shendu(j);
    }
}
int visitedg[n]={0};//�洢 �Ƿ������
int qeeue[n] = {0};
void guangdu(int k)//ʱ�临�Ӷ� n*n �ռ临�Ӷ�n
{
    int i, j;
    int head = 0;
    int tail = 0;
    printf("node:%c \n", a.vexs[k]);//�����ǰ���
    visitedg[k] = 1;
    qeeue[tail++] = k;//k�������
    while(head!=tail)//�����в�Ϊ�յ�ʱ��ѭ��
    {
        i = qeeue[head--];//ȡ������ͷ������
        for (j = 0; j < n;j++)//ѭ������i�����ӵĽ��
        {
            if((a.arcs[i][j]==1)&&(visitedg[j]!=1)) //����ҵ�����i������û�б����Ľ��
            {
                printf("node:%c \n", a.vexs[j]);//�����ǰ���
                visitedg[j] = 1;
                qeeue[tail++] = j;//j���
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