#include <bits/stdc++.h>
#define MAXN 50005
using namespace std;

struct link
{
	int to,nxt;	
};

link e[MAXN<<1];
int head[MAXN], cnt;
int n, k, u, v, w, G, SIZE;
long long ans, h[1024];
int siz[MAXN], mx[MAXN], a[MAXN];
bool vis[MAXN];

template <class _E> inline void read(_E &e)
{
	e=0;bool ck=0;char ch;
	if ((ch=getchar())==EOF){e=-1;return ;}
	while(ch>'9'||ch<'0'){if(ch=='-')ck=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){e=e*10+ch-'0';ch=getchar();}
	if(ck)e=-e;
}

inline void add(int u, int v)
{
	e[cnt] = (link){v, head[u]}; head[u] = cnt++;
	e[cnt] = (link){u, head[v]}; head[v] = cnt++;
}

inline void DFS_size_and_G(int x, int f)
{
	siz[x] = 1;
	mx[x] = 0;
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (e[i].to != f && !vis[e[i].to])
		{
			DFS_size_and_G(e[i].to, x);
			siz[x] += siz[e[i].to];
			mx[x] = max(mx[x], siz[e[i].to]);
		}
	mx[x] = max(mx[x], SIZE - siz[x]);
	if (mx[x] < mx[G]) G = x;
	return ;
}

inline void DFS_col(int x, int f, int col)
{
	++h[col]; siz[x] = 1;
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (e[i].to != f && !vis[e[i].to])
		{
			DFS_col(e[i].to, x, col | (1 << a[e[i].to]));
			siz[x] += siz[e[i].to];
		}
	return ;
}

inline void FWT_Or(long long c[], int n, int f)
{
	long long x, y;
	for (int i = 1; i < n; i <<= 1)
		for (int p = i << 1, j = 0; j < n; j += p)
			for (int k = 0; k < i; k++)
			{
				x = c[j + k];
				y = c[j + k + i];
				c[j + k + i] = y + x * f;
			}
	return ;
}

inline long long Calculate(int x, int dist)
{
	long long res = 0;
	for (int i = 0; i < (1 << k); i++) h[i] = 0;
	DFS_col(x, -1, dist);
	FWT_Or(h, 1 << k, 1);
	for (int i = 0; i < (1 << k); i++) h[i] *= h[i];
	FWT_Or(h, 1 << k, -1);
	return h[(1 << k) - 1];
}

inline void TreeDC(int x)
{
	ans += Calculate(x, 1 << a[x]);
	vis[x] = true;
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (!vis[e[i].to])
		{
			ans -= Calculate(e[i].to, (1 << a[x]) | (1 << a[e[i].to]));
			mx[0] = SIZE = siz[e[i].to];
			G = 0;
			DFS_size_and_G(e[i].to, x);
			TreeDC(G);
		}
	vis[x] = false;
	return ;
}

int main()
{
	while (~scanf("%d %d",&n,&k))
	{
		memset(head,-1,sizeof head);cnt=0;ans=0;
		memset(vis,false,sizeof vis);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]),--a[i];
		for (int i=1;i<n;i++)
		{
			scanf("%d %d",&u,&v);
			add(u,v);
		}
		if (k==1)
		{
			printf("%lld\n",1LL*n*n);
			continue;
		}
		SIZE = mx[0] = n;
		G = 0;
		DFS_size_and_G(1, -1);
		TreeDC(G);
		printf("%lld\n",ans);
	}
	return 0;
}