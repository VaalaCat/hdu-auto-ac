#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int dp[2][11][(1<<8)+5][(1<<8)+5];
bool v1[(1<<8)+5][(1<<8)+5];
bool v2[(1<<8)+5][(1<<8)+5];
int cnt[(1<<8)+5];
int all;
int b[10];
char a[9][9];
int n;

inline void init()
{
	for (int st=0;st<=all;++st)
	{
		for (int i=0;i<8;++i)
		{
			if (st&(1<<i)) ++cnt[st];
		}
		for (int st1=0;st1<=all;++st1)
		{
			if ((st&(st1>>2)) || ((st>>2)&st1))
			v1[st][st1]=1;
		}
		for (int st2=0;st2<=all;++st2)
		{
			if ((st&(st2>>1)) || ((st>>1)&st2))
			v2[st][st2]=1;
		}
	}
}

int main()
{
	all=(1<<8)-1;
	int T;
	cin>>T;
	while (T--)
	{
		memset(dp,0,sizeof dp);
		memset(b,0,sizeof b);
		memset(v1,0,sizeof v1);
		memset(v2,0,sizeof v2);
		memset(cnt,0,sizeof cnt);
		scanf("%d",&n);
		for (int i=0;i<8;++i)
			scanf("%s",a[i]);
		for (int i=0;i<8;++i)
			for (int j=0;j<8;++j)
				if (a[i][j]=='*') b[i]|=(1<<j);
		init();
		int p=0;
		dp[0][0][0][0]=1;
		for (int i=0;i<8;++i)
		{
			p=1-p;
			for (int j=0;j<=n;++j)
				for (int st1=0;st1<=all;++st1)
					for (int st2=0;st2<=all;++st2)
					{
						if (dp[1-p][j][st1][st2]==0) continue;
						for (int st3=0;st3<=all;++st3)
						{
							if (st3&b[i]) continue;
							if (cnt[st3]+j>n) continue;
							if (i>=1 && v1[st2][st3]) continue;
							if (i>=2 && v2[st1][st3]) continue;
							dp[p][j+cnt[st3]][st2][st3]+=dp[1-p][j][st1][st2];
						}
					}
			memset(dp[1-p],0,sizeof dp[1-p]);
		}
		int ans=0;
		for (int st1=0;st1<=all;++st1)
			for (int st2=0;st2<=all;++st2)
				ans+=dp[p][n][st1][st2];
		printf("%d\n",ans);
	}
	return 0;
}