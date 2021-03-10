#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TRUE 1
#define FALSE 0
//-------���Ķѷ���洢��ʾ---------
typedef struct{
    char *ch;   //���Ƿǿմ����򰴴�������洢��������chΪNULL
    int length; //������
}HString;
//------���������ĺ���ԭ��˵��--------
int StrAssign(HString &T, char *chars)//����һ����ֵ���ڴ�����chars�Ĵ�T
{
    char *c=chars;
    int i = 0;
    T.ch = NULL;
    for (; *c;c++)
    {
        i++;
    }
    if(i==0)
    {
        T.length = 0;
        T.ch = NULL;
        return 0;
    }
    else
    {
        T.ch = (char *)malloc(sizeof(char) * i);
        if(T.ch==0)
            exit(0);
        for (int j = 0; j < i;j++)
        {
            T.ch[j] = chars[j];
        }
        T.length = i;
    }
    return 1;
}
int StrLength(HString S)//����S��Ԫ�ظ�������Ϊ���ĳ���
{
    return S.length;
}
int StrCompare(HString S, HString T)//��S>T���򷵻�ֵ>0;��S==T���򷵻�ֵΪ0����S<T���򷵻�ֵ��0
{
    for (int i = 0; i < S.length && i < T.length;i++)
    {
        if(S.ch[i]!=T.ch[i])
            return S.ch[i] - T.ch[i];
    }
    return S.length - T.length;
}
int ClearString(HString &S)//��S��Ϊ�մ������ͷ�S��ռ�ռ�
{
    if(S.ch)
    {
        free(S.ch);
        S.ch = 0;
        S.length = 0;
        return 1;
    }
    return 0;
}
int Concat(HString &T, HString S1, HString S2)//�ô�T������S1��S2���Ӷ��ɵ��´�
{
    int len = S1.length + S2.length;
    T.ch = NULL;
    T.ch = (char *)malloc(sizeof(char) * len);
    if(T.ch==0)
        exit(0);
    T.length = len;
    for (int i = 0; i < S1.length;i++)
    {
        T.ch[i] = S1.ch[i];
    }
    for (int i = 0; i < S2.length;i++)
    {
        T.ch[S1.length + i] = S2.ch[i];
    }
    return 1;
}
int SubString(HString &Sub,HString S, int pos, int len)//���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ�
{
    if(pos<1 || pos>S.length || len<0 || len>S.length-pos+1)
        return 0;
    if(Sub.ch)
        free(Sub.ch);
    if (len==0)
    {
        Sub.ch = NULL;
        Sub.length = 0;
    }
    else
    {
        Sub.ch = (char *)malloc(sizeof(char) * len);
        for (int i = 0; i < len;i++)
            Sub.ch[i] = S.ch[pos + i - 1];
        Sub.length = len;
    }
    return 1;
}
int main()
{
    HString mynew;
    HString mysecond;
    HString my;
    HString u;
    char a[20] = "I love u,";
    char b[20] = "I hate u now!";
    if(StrAssign(mynew,a))
        for (int i = 0; i < StrLength(mynew);i++)
            printf("%c", mynew.ch[i]);
    StrAssign(mysecond, b);
    printf("%d", StrCompare(mynew, mysecond));
    puts("");
    printf("%d:", Concat(my, mynew, mysecond));
    for (int i = 0; i < StrLength(my);i++)
            printf("%c", my.ch[i]);
    puts("");
    SubString(u, my, 12, 4);
    for (int i = 0; i < StrLength(u);i++)
            printf("%c", u.ch[i]);
    return 0;
}