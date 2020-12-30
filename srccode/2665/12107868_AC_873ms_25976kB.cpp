#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <climits>
#include <cctype>
#include <cstdlib>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define llmax LONG_LONG_MAX
#define llmin LONG_LONG_MIN
#define readf(f) scanf("%lf",&f)
#define ls id<<1
#define rs id<<1|1
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
int T,n,m;
int a[100005],root[100005],Hash[100005];
inline void data_clear();
struct President_Tree{
	int l;int r;int sum;
}t[100005<<5];int tsz;
int build(int l,int r)
{
	int id=++tsz;
	t[id].sum=0;
	if (l<r)
	{
		int mid=(l+r)>>1;
		t[id].l=build(l,mid);
		t[id].r=build(mid+1,r);
	}
	return id;
}
int update_tree(int l,int r,int pos,int rt1)
{
	int rt2=++tsz;
	t[rt2]=t[rt1];++t[rt2].sum;
	if (l<r)
	{
		int mid=(l+r)>>1;
		if (pos<=mid) t[rt2].l=update_tree(l,mid,pos,t[rt1].l);
		else t[rt2].r=update_tree(mid+1,r,pos,t[rt1].r);	
	}
	return rt2;
}
int query_tree(int l,int r,int rt1,int rt2,int kth)
{
	if (l>=r) return l;
	int mid=(l+r)>>1;
	int num=t[t[rt2].l].sum-t[t[rt1].l].sum;
	if (num>=kth) return query_tree(l,mid,t[rt1].l,t[rt2].l,kth);
	else return query_tree(mid+1,r,t[rt1].r,t[rt2].r,kth-num);
}

int main()
{
	read(T);
	while (T--)
	{
		data_clear();
		read(n);read(m);
		for (int i=1;i<=n;++i) read(a[i]),Hash[i]=a[i];
		sort(Hash+1,Hash+n+1);
		int d=unique(Hash+1,Hash+n+1)-Hash-1;
		root[0]=build(1,d);
		for (int i=1;i<=n;++i)
		{
			int pos=lower_bound(Hash+1,Hash+d+1,a[i])-Hash;
			root[i]=update_tree(1,d,pos,root[i-1]);
		}
		while (m--)
		{
			int L,R,k;
			read(L),read(R),read(k);
			printf("%d\n",Hash[query_tree(1,d,root[L-1],root[R],k)]);
		}
	}
	return 0;
}
inline void data_clear()
{
	memset(Hash,0,sizeof Hash);
	memset(root,0,sizeof root);
	tsz=0;
}