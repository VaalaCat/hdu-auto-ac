#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;
int a[20];
int dp[20][2];
int r,l;
int dfs(int pos,int pre,int st,bool limit)
{
	if (pos==-1) return 1;
	if (!limit && dp[pos][st]!=-1) return dp[pos][st];
	int up=limit?a[pos]:9;
	int tmp=0;
	for (int i=0;i<=up;i++)
	{
		if ((pre==6 && i==2) || i==4) continue;
		tmp+=dfs(pos-1,i,i==6,limit && i==a[pos]);
	}
	if (!limit) dp[pos][st]=tmp;
	return tmp;
}

int solve(int x)
{
	int pos=0;
	while (x)
	{
		a[pos++]=x%10;
		x/=10;
	}
	return dfs(pos-1,-1,0,1);
}

int main()
{
	while (~scanf("%d%d",&l,&r) && l && r)
	{
		memset(dp,-1,sizeof dp);
		printf("%d\n",solve(r)-solve(l-1));
	}
	return 0;
}