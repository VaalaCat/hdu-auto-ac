#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
char s[110005];
char s1[220005];
int p[220005];
int len;
int len1;

void init()
{
	len=strlen(s);
	memset(p,0,sizeof p);
	for (int i=len;i>=0;i--)
	{
		s[i*2+2]=s[i];
		s[i*2+1]='#';
	}
	s[0]='*';
}

void malache()
{
	int maxr=0,id=0;
	for (int i=2;i<=len*2;i++)
	{
		if (p[id]+id>i) p[i]=min(p[2*id-i],p[id]+id-i);
		else p[i]=1;
		while (s[i-p[i]]==s[i+p[i]]) p[i]++;
		if (id+p[id]<i+p[i]) id=i;
		if (maxr<p[i]) maxr=p[i];
	}
	printf("%d\n",maxr-1);
}

int main()
{
	while (scanf("%s",s)!=EOF)
	{
		init();
		malache();
	}
	return 0;
}