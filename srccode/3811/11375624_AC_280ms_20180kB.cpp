#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
#define Case(x,p) printf("Case %d: %lld\n",x,p)
using namespace std;
ll dp[18][(1<<17)+5];
int a[18*18],b[18*18];
int map[18][18];
int n,m,all;
ll f[18];
int num[(1<<17)+5];

inline void chushi()
{
	memset(dp,0,sizeof dp);
	memset(map,0,sizeof map);
}

void init()
{
	f[1]=1;
	for (int i=2;i<=17;++i)
		f[i]=f[i-1]*i;
}

int main()
{
	init();
	int T,kase=0;
	cin>>T;
	while (T--)
	{
		chushi();
		scanf("%d%d",&n,&m);
		for (int i=1;i<=m;++i)
		{
			scanf("%d%d",&a[i],&b[i]);
			map[--a[i]][--b[i]]=1;
		}
		all=(1<<n)-1;
		dp[0][0]=1;
		for (int i=0;i<n;++i)
		{
			for (int j=0;j<=all;++j)
			{
				if (dp[i][j])
				{
					for (int k=0;k<n;++k)
					{
						if (j&(1<<k) || map[i][k]) continue;
						dp[i+1][j|(1<<k)]+=dp[i][j];
					}
				}
			}
		}
		Case(++kase,f[n]-dp[n][all]);
	}
	return 0;
}