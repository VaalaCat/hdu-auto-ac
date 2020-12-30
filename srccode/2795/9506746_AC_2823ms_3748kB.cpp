#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
struct node{
	int l,r,maxn;
}t[200005<<2];
int h,w,n;
int a[200005<<2];

void build(int l,int r,int id)
{
	a[id]=w;
//	t[l].l=l,t[r].r=r;
	if (l==r)
	{
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,id<<1);
	build(mid+1,r,id<<1|1);
}

int query(int l,int r,int id,int val)
{
	if (l==r)
	{
		a[id]-=val;
		return l;
	}
	int mid=(l+r)>>1;
	int ans=(a[id<<1]>=val)?query(l,mid,id<<1,val):query(mid+1,r,id<<1|1,val);
//	t[id].maxn=max(t[id<<1].maxn,t[id<<1|1].maxn);
	a[id]=max(a[id<<1],a[id<<1|1]);
	return ans;
}

int main()
{
	while (scanf("%d%d%d",&h,&w,&n)!=EOF)
	{
//		memset(a,0,sizeof a);
		h=min(h,n);
		build(1,h,1);
		int x;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if (a[1]<x)
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n",query(1,h,1,x));
			}
		}
	}
	return 0;
}