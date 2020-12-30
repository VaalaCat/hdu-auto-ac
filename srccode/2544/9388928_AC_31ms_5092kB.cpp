#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#define M 200005
#define INF 0x3f3f3f3f
using namespace std;
int n,m;
int head[M/2],k=1,dis[M/2],vis[M/2];
struct edge{
	int vk;
	int wk;
	int nextt;
}e[M];

void ad(int u,int v,int w)
{
	e[k].vk=v;
	e[k].wk=w;
	e[k].nextt=head[u];
	head[u]=k++;
}

queue <int> q;

void sp()
{
	for (int i=1;i<=n;i++) dis[i]=INF;
	dis[1]=0;
	vis[1]=1;
	q.push(1);
	while (!q.empty())
	{
		int u=q.front();
		q.pop();
		vis[u]=0;
		for (int i=head[u];i;i=e[i].nextt)
		{
			int vk=e[i].vk;
			int wk=e[i].wk;
			if (dis[vk]>dis[u]+wk)
			{
				dis[vk]=dis[u]+wk;
				if (!vis[vk])
				{
					vis[vk]=1;
					q.push(vk);
				}
			}
		}
	}
}

int main()
{
//	freopen("A.in","r",stdin);
//	freopen("A.out","w",stdout);
	int x,y,z;
	while (scanf("%d%d",&n,&m)==2 && n && m)
	{
		memset(e,0,sizeof e);
		memset(head,0,sizeof head);
		memset(dis,0,sizeof dis);
		memset(vis,0,sizeof vis);
		for (int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&x,&y,&z);
			ad(x,y,z);
			ad(y,x,z);
		}
		sp();
		printf("%d\n",dis[n]);
	}
	return 0;
}