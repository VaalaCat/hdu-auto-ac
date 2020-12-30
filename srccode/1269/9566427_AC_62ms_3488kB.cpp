#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <stack>
using namespace std;
struct edge{
	int vk;
	int next;
}e[100005];
int head[10005],k=1;
bool vis[10005];
int n,m;
int index,tot;
int low[10005],dnf[10005];
int belong[10005];
int cnt;
stack <int> s;
void ad(int u,int v)
{
	e[k].vk=v;
	e[k].next=head[u];
	head[u]=k++;
}

void tarjan(int u)
{
	int v;
	low[u]=dnf[u]=++tot;
	s.push(u);
	vis[u]=1;
	for (int i=head[u];i;i=e[i].next)
	{
		v=e[i].vk;
		if (!dnf[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if (vis[v])
		{
			low[u]=min(low[u],dnf[v]);
		}
	}
	if (low[u]==dnf[u])
	{
		cnt++;
		while (u!=v)
		{
			v=s.top();
			s.pop();
			vis[v]=0;
			belong[v]=cnt;
		}
	}
}

int main()
{
	while (~scanf("%d%d",&n,&m))
	{
		if (n==0&&m==0) break;
		memset(vis,0,sizeof vis);
		memset(e,0,sizeof e);
		memset(low,0,sizeof low);
		memset(dnf,0,sizeof dnf);
		memset(head,0,sizeof head);
		memset(belong,0,sizeof belong);
		cnt=0,tot=0;
		k=1;
		int x,y;
		for (int i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			ad(x,y);
		}
		for (int i=1;i<=n;i++)
		{
			if (!dnf[i]) tarjan(i);
		}
		if (cnt>1) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}