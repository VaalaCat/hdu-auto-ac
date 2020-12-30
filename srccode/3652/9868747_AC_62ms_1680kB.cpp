#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;
int n;
int a[20];
int dp[20][20][3];

int dfs(int pos,int m,int st,bool limit)
{
	int up,tmp,mod,nextst;
	if (pos<=0)
		return m==0 && st==2;
	if (!limit && dp[pos][m][st]!=-1)
		return dp[pos][m][st];
	up=limit?a[pos]:9;
	tmp=0;
	for (int i=0;i<=up;i++)
	{
		mod=(m*10+i)%13;
		nextst=st;
		if (st==0 && i==1)
		{
			nextst=1;
		}
		if (st==1 && i!=1)
		{
			nextst=0;
		}
		if (st==1 && i==3)
		{
			nextst=2;
		}
		tmp+=dfs(pos-1,mod,nextst,limit && i==up);
	}
	if (!limit) dp[pos][m][st]=tmp;
	return tmp;
}

int solve(int x)
{
	int pos=0;
	while (x)
	{
		a[++pos]=x%10;
		x/=10;
	}
	return dfs(pos,0,0,1);
}

int main()
{
	while (~scanf("%d",&n))
	{
		memset(a,0,sizeof a);
		memset(dp,-1,sizeof dp);
		printf("%d\n",solve(n));
	}
	return 0;
}