#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <climits>
#include <cctype>
#include <vector>
#include <cstdlib>
#define ll long long
#define llmax LONG_LONG_MAX
#define llmin LONG_LONG_MIN
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#define maxn 10500
const int INF=0x3f3f3f3f;
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <class _E> inline void read(_E &e)
{
	e=0;bool ck=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')ck=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){e=e*10+ch-'0';ch=getchar();}
	if(ck)e=-e;
}
struct edge{
	int u,v,cap,flow;
};
struct Dinic{
	int m,s,t;
	vector <edge> edges;
	vector <int> g[maxn];
	int inq[maxn],d[maxn],cur[maxn];
	inline void init()
	{
		memset(inq,0,sizeof inq);
		memset(d,0,sizeof d);
		for (int i=0;i<maxn;++i) g[i].clear();
		edges.clear();
		memset(cur,0,sizeof cur);
	}
	inline void ad(int u,int v,int cap)
	{
		edges.push_back((edge){u,v,cap,0});
		edges.push_back((edge){v,u,0,0});
		m=edges.size();
		g[u].push_back(m-2);g[v].push_back(m-1);
	}
	inline bool bfs()
	{
		memset(inq,0,sizeof inq);
		queue <int> q;
		q.push(s);
		d[s]=0;inq[s]=1;
		
		while (!q.empty())
		{
			int u=q.front();q.pop();
			int siz=g[u].size();
			for (int i=0;i<siz;++i)
			{
				edge &e=edges[g[u][i]];
				if (!inq[e.v] && e.cap>e.flow)
				{
					inq[e.v]=1;
					d[e.v]=d[u]+1;
					q.push(e.v);
				}
			}
		}
		return inq[t];
	}
	int dfs(int u,int a)
	{
		if (u==t || !a) return a;
		int flow=0,f,siz=g[u].size();
		for (int &i=cur[u];i<siz;++i)
		{
			edge &e=edges[g[u][i]];
			if (d[u]+1==d[e.v] && (f=dfs(e.v,min(a,e.cap-e.flow)))>0)
			{
				e.flow+=f;
				edges[g[u][i]^1].flow-=f;
				flow+=f;
				a-=f;
				if (!a) break;
			}
		}
		return flow;
	}
	int maxflow(int s,int t)
	{
		this->s=s,this->t=t;
		int flow=0;
		while (bfs())
		{
			memset(cur,0,sizeof cur);
			flow+=dfs(s,INF);
		}
		return flow;
	}
}dick;
int n,m;
int a[105][105],sum;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

int main()
{
	while (~scanf("%d",&n))
	{
		dick.init();sum=0;
		m=n;
		memset(a,0,sizeof a);
		for (int i=1;i<=n;++i)
			for (int j=1;j<=m;++j)
				read(a[i][j]),sum+=a[i][j];
		int S=n*m+5;int T=S+1;
		for (int i=1;i<=n;++i)
		{
			for (int j=1;j<=m;++j)
			{
				int u=(i-1)*m+j;
				if ((i+j)&1) dick.ad(S,u,a[i][j]);
				else dick.ad(u,T,a[i][j]);
				for (int k=0;k<4;++k)
				{
					int nx=i+dx[k],ny=j+dy[k];
					if (nx<1||nx>n||ny<1||ny>m) continue;
					int v=(nx-1)*m+ny;
					if ((i+j)&1) dick.ad(u,v,INF);
					else dick.ad(v,u,INF);
				}
			}
		}
		int tmp=dick.maxflow(S,T);
		printf("%d\n",sum-tmp);	
	}
	return 0;
}