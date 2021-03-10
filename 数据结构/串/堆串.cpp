#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TRUE 1
#define FALSE 0
//-------串的堆分配存储表示---------
typedef struct{
    char *ch;   //若是非空串，则按串长分配存储区，否则ch为NULL
    int length; //串长度
}HString;
//------基本操作的函数原型说明--------
int StrAssign(HString &T, char *chars)//生成一个其值等于串常量chars的串T
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
int StrLength(HString S)//返回S的元素个数，称为串的长度
{
    return S.length;
}
int StrCompare(HString S, HString T)//若S>T，则返回值>0;若S==T，则返回值为0，若S<T，则返回值＜0
{
    for (int i = 0; i < S.length && i < T.length;i++)
    {
        if(S.ch[i]!=T.ch[i])
            return S.ch[i] - T.ch[i];
    }
    return S.length - T.length;
}
int ClearString(HString &S)//将S清为空串，并释放S所占空间
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
int Concat(HString &T, HString S1, HString S2)//用串T返回由S1和S2联接而成的新串
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
int SubString(HString &Sub,HString S, int pos, int len)//返回串S的第pos个字符起长度为len的子串
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