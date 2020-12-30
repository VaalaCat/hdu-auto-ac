#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <climits>
#define ll long long
#pragma comment(linker, "/STACK:1024000000,1024000000")
template <class _E> inline void read(_E &e)
{
	e=0;bool ck=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')ck=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){e=e*10+ch-'0';ch=getchar();}
	if(ck)e=-e;
}
const ll mod=1e9+7;
using namespace std;
int n,m;
struct edge{
	int vk;
	int nxt;
}e[200005];
int k,head[100005];
int in[100005],out[100005];
int dfn[100005];
ll a[100005];
ll dis[100005];
int idx;
struct tree{
	int l,r;
	ll maxn,lazy;
}t[100005<<2];
inline void ad(int u,int v)
{
	e[++k].vk=v;
	e[k].nxt=head[u];
	head[u]=k;
}

void dfsxu(int u,int fa)
{
	in[u]=++idx;
	dfn[idx]=u;
	for (int i=head[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].vk;
		if (v==fa) continue;
		dis[v]=dis[u]+a[v];
		dfsxu(v,u);
	}
	out[u]=idx;
}

inline void down(int id)
{
	if (t[id].lazy)
	{
		t[id<<1].maxn+=t[id].lazy;
		t[id<<1|1].maxn+=t[id].lazy;
		t[id<<1].lazy+=t[id].lazy;
		t[id<<1|1].lazy+=t[id].lazy;
		t[id].lazy=0;
	}
}

inline void up(int id)
{
	t[id].maxn=max(t[id<<1].maxn,t[id<<1|1].maxn);
}

void build(int l,int r,int id)
{
	t[id].l=l,t[id].r=r;
	if (l==r)
	{
		t[id].maxn=dis[dfn[l]];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,id<<1);
	build(mid+1,r,id<<1|1);
	up(id);
}
//
//void update(int L,int R,ll val,int l,int r,int id)
//{
//	if (L<=l && r<=R)
//	{
//		t[id].maxn+=val;
//		t[id].lazy+=val;
//		return;
//	}
//	down(id);
//	int mid=(l+r)>>1;
//	if (L<=mid) update(L,R,val,l,mid,id<<1);
//	if (R>mid) update(L,R,val,mid+1,r,id<<1|1);
//	up(id);
//}

void update(int id,int l,int r,ll val)
{
	if(t[id].l==l&&t[id].r==r)
	{
		t[id].maxn+=val;
		t[id].lazy+=val;
		return;
	}
	down(id);
	int mid=(t[id].l+t[id].r)>>1;
	if(mid>=r) update(id<<1,l,r,val);
	else if(mid<l) update(id<<1|1,l,r,val);
	else update(id<<1,l,mid,val),update(id<<1|1,mid+1,r,val);
	up(id);	
}

ll query(int id,int l,int r)
{
	if(t[id].l==l&&t[id].r==r)
		return t[id].maxn;
	down(id);
	int mid=(t[id].l+t[id].r)>>1;
	if(mid>=r) return query(id<<1,l,r);
	else if(mid<l) return query(id<<1|1,l,r);
	else return max(query(id<<1,l,mid),query(id<<1|1,mid+1,r));
}

int main()
{
	int T,kas=0;
	read(T);
	while (T--)
	{
		memset(dis,0,sizeof dis);
		memset(head,-1,sizeof head),k=0;
		memset(in,0,sizeof in);
		memset(out,0,sizeof out);
		memset(t,0,sizeof t);
		idx=0;
		read(n),read(m);
		for (int i=1;i<n;++i)
		{
			int x,y;
			read(x),read(y);
			ad(x,y),ad(y,x);
		}
		for (int i=0;i<n;++i)
			read(a[i]);
		dis[0]=a[0];
		dfsxu(0,-1);
		build(1,n,1);
		++kas;
		cout<<"Case #"<<kas<<":"<<endl;
		while (m--)
		{
			int op,x,y;
			read(op);
			if (op==0)
			{
				read(x),read(y);
				update(1,in[x],out[x],y-a[x]);
				a[x]=y;
			}
			else
			{
				read(x);
				printf("%lld\n",query(1,in[x],out[x]));
			}
		}
	}
	return 0;
}