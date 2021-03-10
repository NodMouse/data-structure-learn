#include<stdio.h>
#define n 6//叶子数目
#define m 2*n-1 //节点总数
#define discon 9999.99;
typedef struct
{
    int weight;
    char data;
    int lchild, rchild, father;
} hufuman;
typedef struct{ //构建的哈夫曼树左子树分配0，右子树分配1 n个叶子结点最大编码长度不会超过n-1
    char bits[n];//数组位串
    int start;//编码在位串中起始位置
    char data;//数据值
} hufucode;
hufucode code[n];
hufuman tree[m];
void build(hufuman tree[])
{
    int i, j, p1, p2;
    char ch;
    int small1, small2, f;
    for (i = 0; i < m;i++)//初始化为0
    {
        tree[i].father = 0;
        tree[i].lchild = 0;
        tree[i].rchild = 0;
        tree[i].weight = 0.0;
        tree[i].data = 0;
    }
    for (i = 0; i < n;i++)//键入叶子结点的值
    {
        scanf("%d", &f);
        tree[i].weight = f;
        getchar();
        scanf("%c", &ch);
        tree[i].data = ch;
    }
    for (i = n; i < m;i++)//生成除了叶子结点外的结点的值
    {
        p1 = p2 = 0;
        small1 = small2 =9999;//初始化
        for (j = 0; j <= i - 1;j++)//遍历前i个找到最小的和次小的没有父亲的结点和他们的位置
        {
            if(tree[j].father==0)//如果是没有父亲（还没有加入树）
            {
                if(tree[j].weight<small1)//如果当前结点的权重比当前最小的还要小则当前最小的变成次小，当前结点变为最小
                {
                    small2 = small1;
                    small1 = tree[j].weight;
                    p2 = p1;
                    p1 = j;
                }
                else if(tree[j].weight<small2)//否则如果当前结点比次小的还要小，则当前结点变为次小的
                {
                    small2 = tree[j].weight;
                    p2 = j;
                }
            }
            printf("p1:%d small1:%d p2:%d small2:%d | ", p1,small1, p2,small2);
        }//到此我们在此轮循环找到了最小的和次小的没有加入树的结点p1,p2和她们的权值small1 small2
        printf("______________________________________________________________\n");
        tree[p1].father = i;
        tree[p2].father = i;
        tree[i].lchild = p1;
        tree[i].rchild = p2;
        tree[i].weight = tree[p1].weight + tree[p2].weight;

    }
}
void getcode(hufucode code[],hufuman tree[])
{
    int i, c, p;
    hufucode cd;
    for (i = 0; i < n;i++)//遍历叶子结点
    {
        cd.start = n;
        c = i;
        p = tree[c].father;
        cd.data = tree[c].data;
        while(p!=0)
        {
            cd.start--;
            if(tree[p].lchild==c)
                cd.bits[cd.start] = '0';
            else
                cd.bits[cd.start] = '1';
            c = p;
            p = tree[c].father;
        }
        code[i] = cd;
    }
}
void decode(hufuman tree[ ]){ 
    int i, b;
    int endflag=-1;             /* 电文结束标志取-1 */ 
    i=m-1;                    /* 从根结点开始向下搜索*/
    scanf ("%d", &b);         /* 读入一个二进制代码*/ 
    while ( b != endflag)    
    {
        if( b==0)   
            i=tree[i].lchild;   /* 走向左孩子*/
        else   
            i=tree[i].rchild;        /* 走向右孩子*/
        if ( tree[i].lchild==0 )        /* tree[i]是叶子结点*/
        {       
            putchar( code[i].data);
            i=m-1;                /*  回到根结点*/
        }
        scanf("%d",  &b);         /* 读入下一个二进制代码*/
    }
    if ((tree[i].lchild!=0)&&(i!=m-1) ) /*电文读完尚未到叶子结点*/ 
    printf( "ERROr!\n");              /* 输入电文有错*/
}
int main()
{
    hufucode code[n];
    hufuman tree[m];
    build(tree);
    getcode(code, tree);
    /*for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < 6;j++)
            printf("%c", code[i].bits[j]);
        printf(":\n");
    }*/
    for (int i = 0; i < m;i++)
    {
        printf("%d %d %c %d %d %d\n", i, tree[i].lchild, tree[i].data, tree[i].weight, tree[i].rchild, tree[i].father);
    }
}