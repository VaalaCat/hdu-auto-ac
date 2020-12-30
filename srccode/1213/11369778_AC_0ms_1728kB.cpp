#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
int n,m;
int f[1005];
int find(int x)
{
	return x==f[x]?x:f[x]=find(f[x]);
}
inline void initf()
{
	for (int i=1;i<=n;++i) f[i]=i;
}
bool vis[1005];

int main()
{
	int T;
	cin>>T;
	while (T--)
	{
		scanf("%d%d",&n,&m);
		initf();
		memset(vis,0,sizeof vis);
		for (int i=1;i<=m;++i)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			int px=find(x),py=find(y);
			f[px]=py;
		}
		for (int i=1;i<=n;++i)
		{
			vis[find(i)]=1;
		}
		int ans=0;
		for (int i=1;i<=n;++i)
		{
			if (vis[i]) ++ans;
		}
		cout<<ans<<endl;
	}
	return 0;
}