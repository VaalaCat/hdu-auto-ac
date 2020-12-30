#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#define null 0
#define ll long long
#define eps 1e-18
using namespace std;
template <class _E> inline void read(_E &e)
{
	e=0;bool ck=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')ck=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){e=e*10+ch-'0';ch=getchar();}
	if(ck)e=-e;
}
double dp[(1<<20)+5];
int id[25];
double p[25];
int n,all;

int main()
{
	id[1]=1;
	for (int i=2;i<=20;++i)
		id[i]=(id[i-1]<<1);
	while (~scanf("%d",&n))
	{
		all=(1<<n)-2;
		double ans=1.0;
		for (int i=1;i<=n;++i)
			scanf("%lf",&p[i]),ans-=p[i];
		memset(dp,0,sizeof dp);
		for (int st=all;st>=0;--st)
		{
			double cnt=0,sum=1;
			for (int i=1;i<=n;++i)
			{
				if (st&id[i]) cnt+=p[i];
				else sum+=dp[st|id[i]]*p[i];
			}
			dp[st]=sum/(1.0-cnt-ans);
		}
		printf("%.7lf\n",dp[0]);
	}
	return 0;
}