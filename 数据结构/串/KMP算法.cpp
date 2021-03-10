#include <stdio.h>
#define MaxStrlen 20
typedef unsigned char SString[MaxStrlen + 1];
void getnext(SString T, int *next)
{
	next[1] = 0;
	int i = 1;
	int j = 0;
	while(i<T[0])
	{
		if(j==0 ||T[i]==T[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}
void getvalnext(SString T, int *next)
{
	next[1] = 0;
	int i = 1;
	int j = 0;
	while(i<T[0])
	{
		if(j==0 ||T[i]==T[j])
		{
			++i;
			++j;
			if(T[i]!=T[j])
				next[i] = j;
			else
				next[i] = next[j];
		}
		else
		{
			j = next[j];
		}
	}
}
int KPM(SString S,SString T,int *next)
{
	int i = 1;
	int j = 1;
	while(i<=S[0] && j<=T[0])
	{
		if(S[i]==T[j] || j==0)
		{
			++i;
			++j;
		}
		else
		{
			j = next[j];
		}
	}
	if(j>T[0])
		return i-T[0];
	return 0;
}
int main(void)
{
	int i;
	int next[7]={0};
	int valnext[7]={0};
	SString S = " acabaabaabcacaabc",
			T = " abaabc";
	S[0] = 17;
	T[0] = 6;
	getnext(T, next);
	getvalnext(T, valnext);
	for (i=1; i<=6; i++)
		printf("%d", next[i]);
	puts("");
	for (i=1; i<=6; i++)
		printf("%d", valnext[i]);
	puts("");
	printf("%d", KPM(S, T, next));
	return 0;
}