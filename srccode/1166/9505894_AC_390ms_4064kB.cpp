#include <cstdio>
#include <cstring>
using namespace std;
int T;
int a[50005];
int n;
struct node{
	int l,r;
	int sum;
}t[50005<<2];

void build(int l,int r,int id)
{
	t[id].l=l,t[id].r=r;
	if (l==r)
	{
		t[id].sum=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,id<<1);
	build(mid+1,r,id<<1|1);
	t[id].sum=t[id<<1].sum+t[id<<1|1].sum;
}

void add(int pos,int val,int id)
{
	int l=t[id].l,r=t[id].r;
	if(l==r)
	{
		t[id].sum+=val;
		return;
	}
	int mid=(l+r)>>1;
	if (pos<=mid) add(pos,val,id<<1);
	else add(pos,val,id<<1|1);
	t[id].sum=t[id<<1].sum+t[id<<1|1].sum;
}

void sub(int pos,int val,int id)
{
	int l=t[id].l,r=t[id].r;
	if(l==r)
	{
		t[id].sum-=val;
		return;
	}
	int mid=(l+r)>>1;
	if (pos<=mid) sub(pos,val,id<<1);
	else sub(pos,val,id<<1|1);
	t[id].sum=t[id<<1].sum+t[id<<1|1].sum;
}

int query(int l,int r,int id)
{
	int x=t[id].l,y=t[id].r;
	if (l==x&&r==y)
	{
		return t[id].sum;
	}
	int mid=(x+y)>>1;
	if (r<=mid) return query(l,r,id<<1);
	else if (l>mid) return query(l,r,id<<1|1);
	else return query(l,mid,id<<1)+query(mid+1,r,id<<1|1);
}

int main()
{
	scanf("%d",&T);
	int kase=1;
	while (T--)
	{
		memset(a,0,sizeof a);
		memset(t,0,sizeof t);
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		char s[15];
		int x,y;
		build(1,n,1);
		printf("Case %d:\n",kase++);
		while (scanf("%s",s))
		{ 
			if (s[0]=='E') break;
			if (s[0]=='Q')
			{
				scanf("%d%d",&x,&y);
				printf("%d\n",query(x,y,1));
			}
			else if (s[0]=='S')
			{
				scanf("%d%d",&x,&y);
				sub(x,y,1);
			}
			else if (s[0]=='A')
			{
				scanf("%d%d",&x,&y);
				add(x,y,1);
			}
			memset(s,0,sizeof s);
		}
	}
	return 0;
}