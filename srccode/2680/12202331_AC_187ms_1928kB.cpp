#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
const int maxn=0x3f3f3f3f;
using namespace std;
struct edge{
	int vk;
	int wk;
	int nxt;
}e[20005+1005];
int n,m,S;
int head[1010],t;
int dis[1010];bool vis[1010];
inline void adw(int u,int v,int w)
{
	e[++t].vk=v;e[t].wk=w;
	e[t].nxt=head[u];head[u]=t;
}
inline void data_clear();
queue <int> q;
void sp()
{
	q.push(1005);
	vis[1005]=1;
	dis[1005]=0;
	while (!q.empty())
	{
		int u=q.front();
		q.pop();
		vis[u]=0;
		for (int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].vk;
			int w=e[i].wk;
			if (dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				if (!vis[v]) vis[v]=1,q.push(v);
			}
		}
	}
}

int main()
{
	while (~scanf("%d%d%d",&n,&m,&S))
	{
		data_clear();
		for (int i=1;i<=m;++i)
		{
			int P,Q,s;
			scanf("%d%d%d",&P,&Q,&s);
			adw(P,Q,s);
		}
		int W;
		scanf("%d",&W);
		while (W--)
		{
			int x;
			scanf("%d",&x);
			adw(1005,x,0);
		}
		sp();
		if (dis[S]==maxn) puts("-1");
		else printf("%d\n",dis[S]);
	}
	return 0;
}
inline void data_clear()
{
	memset(head,0,sizeof head),t=0;
	memset(dis,maxn,sizeof dis);
	memset(vis,0,sizeof vis);
	while (!q.empty()) q.pop();
}
