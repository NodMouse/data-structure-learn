#include<stdio.h>
#define n 6//Ҷ����Ŀ
#define m 2*n-1 //�ڵ�����
#define discon 9999.99;
typedef struct
{
    int weight;
    char data;
    int lchild, rchild, father;
} hufuman;
typedef struct{ //�����Ĺ�����������������0������������1 n��Ҷ�ӽ�������볤�Ȳ��ᳬ��n-1
    char bits[n];//����λ��
    int start;//������λ������ʼλ��
    char data;//����ֵ
} hufucode;
hufucode code[n];
hufuman tree[m];
void build(hufuman tree[])
{
    int i, j, p1, p2;
    char ch;
    int small1, small2, f;
    for (i = 0; i < m;i++)//��ʼ��Ϊ0
    {
        tree[i].father = 0;
        tree[i].lchild = 0;
        tree[i].rchild = 0;
        tree[i].weight = 0.0;
        tree[i].data = 0;
    }
    for (i = 0; i < n;i++)//����Ҷ�ӽ���ֵ
    {
        scanf("%d", &f);
        tree[i].weight = f;
        getchar();
        scanf("%c", &ch);
        tree[i].data = ch;
    }
    for (i = n; i < m;i++)//���ɳ���Ҷ�ӽ����Ľ���ֵ
    {
        p1 = p2 = 0;
        small1 = small2 =9999;//��ʼ��
        for (j = 0; j <= i - 1;j++)//����ǰi���ҵ���С�ĺʹ�С��û�и��׵Ľ������ǵ�λ��
        {
            if(tree[j].father==0)//�����û�и��ף���û�м�������
            {
                if(tree[j].weight<small1)//�����ǰ����Ȩ�رȵ�ǰ��С�Ļ�ҪС��ǰ��С�ı�ɴ�С����ǰ����Ϊ��С
                {
                    small2 = small1;
                    small1 = tree[j].weight;
                    p2 = p1;
                    p1 = j;
                }
                else if(tree[j].weight<small2)//���������ǰ���ȴ�С�Ļ�ҪС����ǰ����Ϊ��С��
                {
                    small2 = tree[j].weight;
                    p2 = j;
                }
            }
            printf("p1:%d small1:%d p2:%d small2:%d | ", p1,small1, p2,small2);
        }//���������ڴ���ѭ���ҵ�����С�ĺʹ�С��û�м������Ľ��p1,p2�����ǵ�Ȩֵsmall1 small2
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
    for (i = 0; i < n;i++)//����Ҷ�ӽ��
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
    int endflag=-1;             /* ���Ľ�����־ȡ-1 */ 
    i=m-1;                    /* �Ӹ���㿪ʼ��������*/
    scanf ("%d", &b);         /* ����һ�������ƴ���*/ 
    while ( b != endflag)    
    {
        if( b==0)   
            i=tree[i].lchild;   /* ��������*/
        else   
            i=tree[i].rchild;        /* �����Һ���*/
        if ( tree[i].lchild==0 )        /* tree[i]��Ҷ�ӽ��*/
        {       
            putchar( code[i].data);
            i=m-1;                /*  �ص������*/
        }
        scanf("%d",  &b);         /* ������һ�������ƴ���*/
    }
    if ((tree[i].lchild!=0)&&(i!=m-1) ) /*���Ķ�����δ��Ҷ�ӽ��*/ 
    printf( "ERROr!\n");              /* ��������д�*/
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