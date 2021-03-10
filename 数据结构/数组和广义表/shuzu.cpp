#include<stdio.h>
//������Ϊ������ a[i][j]=a[1][1]+(i-1)*n+(j-1) * a[i][j]=a[1][1]+(i-1)*n+(j-1)*length
//�������� a[i][j]=a[1][1]+(j-1)m+(i-1) * a[i][j]=a[1][1]+(j-1)m+(i-1)*length
int(a[2])[20];
//������� �Գƾ���(һ���Ƿ���) a[i][j]==a[j][i];����ֻ�洢�����ǻ���������Ԫ�� Ԫ������Ϊn(n+1)/2 ��ΪҪ�洢�Խ���Ԫ�����Բ���n*n/2
//���Ǿ���ֻ���������ǺͶԽ���Ԫ�أ� �����ڶԳƾ��� ���ǲ�һ���Ƿ��� ���Ϊ���� �洢�����ͶԳ�һ�� ��Ϊ����k=i(i+1)/2+j
//�ԽǾ���ֻ�жԽ��ߺͶԽ������ߵ�������ֵ ��0�к�n-1����2��Ԫ�� �����඼��3��Ԫ�أ����Դ洢����Ϊ3n-2 ��i j��Ԫ�ص�Ϊk=(2i+j)
#define maxsize 10000//ϡ�����Ĵ洢 �����������ֵ��ڶ�ʮ��֮һʱΪϡ����� t/n*m=O(t)
typedef int datatype; //����洢i=1 j=2 v=20 Ԫ��� ��ʾ��һ�еڶ��д洢20 
struct node
{
    int i,j;  //������Ԫ����С��к�
    int v;   //��Ԫ���ֵ
};
typedef struct sparmatrix
{
    int rows,cols; //ϡ�������С�����
    int terms;   //ϡ�����ķ���Ԫ����
    struct node data[maxsize]; //���ϡ��������Ԫ���
}matrix;
int TransMatrix(matrix M,matrix &T)//��ϡ�����M��ת�þ���T
{
    T.rows = M.cols;
    T.cols = M.rows;
    T.terms = M.terms;//���洢�����и����ͷ���Ԫ��������
    if(T.terms)//�����Ϊ��
    {
        int now = 1;//������������ĵڼ����ı��
        for (int col = 1; col < M.cols;++col)//�ӵ�һ�п�ʼ����
            for (int search = 1; search <= M.rows;++search)//��������M����ĵڼ������
                if(M.data[search].j==col){ //���ƥ����
                    T.data[now].i = M.data[search].j; 
                    T.data[now].j = M.data[search].i;
                    T.data[now].v = M.data[search].v;//��ֵ
                    ++now; //��������+1
                }
    }
    return 1;
}//ʱ�临�ӶȺܸ�O(col*terms)
/////ʮ������
typedef struct OLNode{
    int i, j;//�����±�
    int data;
    struct OLNode *right, *down;//�����б�ĺ����
} OLNode,
*OLink;
typedef struct{
    OLink *rhead, *chead;//��ͷ����ͷ
    int mu, nu, tu;//������ �ͷ���Ԫ
}CrossList;
//�����
typedef enum
{
    ATOM,
    LIST
} ElemTag;//ԭ�Ӻ��ӱ�ڵ�
typedef struct GLNode{
    ElemTag tag;//����ԭ�Ӻ��ӱ�ı��
    union{
        int atom;//ԭ�ӵ�ֵ��
        struct GLNode *hp; //�ӱ�ڵ�ͷָ��
    };
    struct GLNode *next; //nextָ��
} * GList;