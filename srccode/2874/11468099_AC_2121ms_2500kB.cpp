#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <climits>
using namespace std;
template <class _E> inline void read(_E &e)
{
	e=0;bool ck=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')ck=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){e=e*10+ch-'0';ch=getchar();}
	if(ck)e=-e;
}
int n,m,c;
struct edge{
	int vk;
	int wk;
	int nxt;
}e[40005];
int t,head[10005];
inline void ad(int u,int v,int w)
{
	e[++t].vk=v;
	e[t].wk=w;
	e[t].nxt=head[u];
	head[u]=t;
}
int f[10005];
bool vis[10005];
int cnt,fa[10005];
int find(int x)
{
	return x==f[x]?x:f[x]=find(f[x]);
}
int dep[10005];
int p[10005][10];
int dis[10005];

void dfslca(int u)
{
	for (int i=1;i<=9;++i)
		p[u][i]=p[p[u][i-1]][i-1];
	for (int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].vk;
		if (v==p[u][0]) continue;
		dep[v]=dep[u]+1;
		p[v][0]=u;
		dis[v]=dis[u]+e[i].wk;
		dfslca(v);
	}
}

inline int lca(int x,int y)
{
	if (dep[y]<dep[x]) swap(x,y);
	for (int i=9;i>=0;--i)
	{
		if (dep[y]-(1<<i)<dep[x]) continue;
		y=p[y][i];
	}
	if (x==y) return x;
	for (int i=9;i>=0;--i)
	{
		if (p[x][i]==p[y][i]) continue;
		x=p[x][i],y=p[y][i];
	}
	return p[y][0];
}

int main()
{
	while (~scanf("%d%d%d",&n,&m,&c))
	{
		memset(head,0,sizeof head),t=0,cnt=0;
		memset(dep,0,sizeof dep);
		memset(dis,0,sizeof dis);
		memset(p,0,sizeof p);
		memset(vis,0,sizeof vis);
		for (int i=1;i<=n;++i) f[i]=i;
		for (int i=1;i<=m;++i)
		{
			int x,y,z;
			read(x),read(y),read(z);
			ad(x,y,z),ad(y,x,z);
			int px=find(x),py=find(y);
			if (px!=py) f[px]=py;
		}
		for (int i=1;i<=n;++i)
		{
			int pf=find(i);
			if (!vis[pf]) vis[pf]=1,fa[++cnt]=pf;
		}
		for (int i=1;i<=cnt;++i)
			ad(fa[i],n+1,0),ad(n+1,fa[i],0);
		dfslca(n+1);
		while (c--)
		{
			int x,y;
			read(x),read(y);
			int px=find(x),py=find(y);
			if (px!=py)
				puts("Not connected");
			else
			{
				printf("%d\n",dis[x]+dis[y]-2*dis[lca(x,y)]);
			}
		}	
	}
	
	return 0;
}