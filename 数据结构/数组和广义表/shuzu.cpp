#include<stdio.h>
//以行序为主序存放 a[i][j]=a[1][1]+(i-1)*n+(j-1) * a[i][j]=a[1][1]+(i-1)*n+(j-1)*length
//以列序列 a[i][j]=a[1][1]+(j-1)m+(i-1) * a[i][j]=a[1][1]+(j-1)m+(i-1)*length
int(a[2])[20];
//特殊矩阵 对称矩阵(一定是方阵) a[i][j]==a[j][i];所以只存储上三角或者下三角元素 元素总数为n(n+1)/2 因为要存储对角线元素所以不是n*n/2
//三角矩阵（只有上下三角和对角线元素） 类似于对称矩阵 但是不一定是方阵 如果为方阵 存储总数和对称一样 不为方阵k=i(i+1)/2+j
//对角矩阵，只有对角线和对角线两边的数字有值 第0行和n-1行是2个元素 ，其余都是3个元素，所以存储总数为3n-2 第i j个元素的为k=(2i+j)
#define maxsize 10000//稀疏矩阵的存储 三当非零数字低于二十分之一时为稀疏矩阵 t/n*m=O(t)
typedef int datatype; //比如存储i=1 j=2 v=20 元组表 表示第一行第二列存储20 
struct node
{
    int i,j;  //定义三元组的行、列号
    int v;   //三元组的值
};
typedef struct sparmatrix
{
    int rows,cols; //稀疏矩阵的行、列数
    int terms;   //稀疏矩阵的非零元个数
    struct node data[maxsize]; //存放稀疏矩阵的三元组表
}matrix;
int TransMatrix(matrix M,matrix &T)//求稀疏矩阵M的转置矩阵T
{
    T.rows = M.cols;
    T.cols = M.rows;
    T.terms = M.terms;//将存储的行列个数和非零元数量传入
    if(T.terms)//如果不为空
    {
        int now = 1;//往新数组填入的第几个的标号
        for (int col = 1; col < M.cols;++col)//从第一列开始遍历
            for (int search = 1; search <= M.rows;++search)//遍历的是M数组的第几个标号
                if(M.data[search].j==col){ //如果匹配了
                    T.data[now].i = M.data[search].j; 
                    T.data[now].j = M.data[search].i;
                    T.data[now].v = M.data[search].v;//赋值
                    ++now; //新数组标号+1
                }
    }
    return 1;
}//时间复杂度很高O(col*terms)
/////十字链表
typedef struct OLNode{
    int i, j;//行列下标
    int data;
    struct OLNode *right, *down;//所在行表的后继链
} OLNode,
*OLink;
typedef struct{
    OLink *rhead, *chead;//行头和列头
    int mu, nu, tu;//行列数 和非零元
}CrossList;
//广义表
typedef enum
{
    ATOM,
    LIST
} ElemTag;//原子和子表节点
typedef struct GLNode{
    ElemTag tag;//区分原子和子表的标记
    union{
        int atom;//原子的值域
        struct GLNode *hp; //子表节点头指针
    };
    struct GLNode *next; //next指针
} * GList;