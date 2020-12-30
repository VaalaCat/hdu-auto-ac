#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <climits>
#include <vector>
#define ll long long
using namespace std;
template <class _E> inline void read(_E &e)
{
	e=0;bool ck=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')ck=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){e=e*10+ch-'0';ch=getchar();}
	if(ck)e=-e;
}
int n,m,ans;
struct edge{
	int vk;
	int nxt;
}e[200005];
int k,head[100005];
int f[100005];
int p[100005][17],dep[100005];
inline void ad(int u,int v)
{
	e[++k].vk=v;
	e[k].nxt=head[u];
	head[u]=k;
}

struct state{
	int l,r;
	int lca;
	int deep;
}a[100005];
inline bool cmp(const state &x,const state &y)
{
	return x.deep>y.deep;
}

void dfslca(int u)
{
	for (int i=1;i<=16;++i)
		p[u][i]=p[p[u][i-1]][i-1];
	for (int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].vk;
		if (v==p[u][0]) continue;
		dep[v]=dep[u]+1;
		p[v][0]=u;
		dfslca(v);
	}
}
inline int lca(int x,int y)
{
	if (dep[y]<dep[x]) swap(x,y);
	for (int i=16;i>=0;--i)
	{
		if (dep[y]-(1<<i)<dep[x]) continue;
		y=p[y][i];
	}
	if (x==y) return x;
	for (int i=16;i>=0;--i)
	{
		if (p[x][i]==p[y][i]) continue;
		x=p[x][i],y=p[y][i];
	}
	return p[y][0];
}

inline void chushi()
{
	memset(f,0,sizeof f);
	memset(head,0,sizeof head),k=0,ans=0;
	memset(dep,0,sizeof dep);
	memset(p,0,sizeof p);
}

void dfs(int u)
{
	f[u]=1;
	for (int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].vk;
		if (v==p[u][0] || f[v]) continue;
		dfs(v);
	}
}

int main()
{
	while (~scanf("%d%d",&n,&m))
	{
		chushi();
		for (int i=1;i<n;++i)
		{
			int x,y;
			read(x),read(y);
			ad(x,y),ad(y,x);
		}
		dfslca(1);
		for (int i=1;i<=m;++i)
		{
			read(a[i].l),read(a[i].r);
			a[i].lca=lca(a[i].l,a[i].r);
			a[i].deep=dep[a[i].lca];
		}
		sort(a+1,a+m+1,cmp);
		for (int i=1;i<=m;++i)
		{
			if (f[a[i].l] || f[a[i].r]) continue;
			dfs(a[i].lca);
			++ans;
		}
		cout<<ans<<endl;
	}
	return 0;
}