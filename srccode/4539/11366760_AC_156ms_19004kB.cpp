#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int dp[105][205][205];
int b[105];
int cnt[205];
int state[205];
int a[105][105];
int n,m,all;
int sum;

void data_clear()
{
	sum=0;
	memset(dp,0,sizeof dp);
	memset(cnt,0,sizeof cnt);
	memset(b,0,sizeof b);
	memset(state,0,sizeof state);
}

int main()
{
	while (~scanf("%d%d",&n,&m))
	{
		data_clear();
		all=(1<<m)-1;
		for (int i=0;i<n;++i)
			for (int j=0;j<m;++j)
				scanf("%d",&a[i][j]);
		for (int i=0;i<n;++i)
			for (int j=0;j<m;++j)
				if (a[i][j]==0) b[i]|=(1<<j);
		for (int st=0;st<=all;++st)
		{
			int tmp=st;
			if ((st&(st<<2)) || (st&(st>>2)))
				continue;
			while (tmp)
			{
				cnt[sum]+=(tmp&1);
				tmp>>=1;
			}
			state[sum]=st;
			sum++;
		}
		for (int i=0;i<sum;++i)
		{
			if (state[i]&b[0]) continue;
			dp[0][i][0]=cnt[i];
		}
		for (int i=0;i<sum;++i)
		{
			if (state[i]&b[1]) continue;
			for (int j=0;j<sum;++j)
			{
				if (state[j]&b[0]) continue;
				if (((state[i]>>1)&state[j]) || ((state[j]>>1)&state[i]))
					continue;
				dp[1][i][j]=max(dp[1][i][j],dp[0][j][0]+cnt[i]);
			}
		}
		for (int i=2;i<n;++i)
		{
			for (int j=0;j<sum;++j)
			{
				if (state[j]&b[i]) continue;
				for (int k=0;k<sum;++k)
				{
					if (state[k]&b[i-1]) continue;
					if (((state[j]>>1)&state[k]) || ((state[k]>>1)&state[j]))
							continue;
					for (int l=0;l<sum;++l)
					{
						if (state[l]&b[i-2]) continue;
						if (state[l]&state[j]) continue;
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][k][l]+cnt[j]);
					}
				}
			}
		}
		int ans=0;
		for (int i=0;i<sum;++i)
			for (int j=0;j<sum;++j)
				ans=max(ans,dp[n-1][i][j]);
		cout<<ans<<endl;
	}
	return 0;
}