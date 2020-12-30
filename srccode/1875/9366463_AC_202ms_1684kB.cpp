#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int n,t;
int f[405];
int find(int x)
{
	return x==f[x]?x:f[x]=find(f[x]);
}

inline double d(int x1,int y1,int x2,int y2)
{
	return (double)sqrt((double)(x1-x2)*(x1-x2)+(double)(y1-y2)*(y1-y2));
}

struct node{
	int x;
	int y;
}a[405];

struct edge{
	int x;
	int y;
	double w;
}e[10005];

bool cmp(const edge &a,const edge &b)
{
	return a.w<b.w;
}

inline int min(int x,int y)
{
	return x<y?x:y;
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(f,0,sizeof f);
		memset(e,0,sizeof e);
		memset(a,0,sizeof a);
		scanf("%d",&n);
		int x,y;
		for (int i=1;i<=n;i++)
		{
			scanf("%d%d",&x,&y);
			a[i].x=x;
			a[i].y=y;
		}
		int tot=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				if (i!=j)
				{
					tot++;
					e[tot].x=i;
					e[tot].y=j;
					e[tot].w=(double)d(a[i].x,a[i].y,a[j].x,a[j].y);
				}
			}
		}
		double ans=0;
		int cnt=0;
		sort(e+1,e+tot+1,cmp);
		for (int i=1;i<=n;i++) f[i]=i;
		for (int i=1;i<=tot;i++)
		{
			if (e[i].w>1000.0) continue;
			if( e[i].w<10) continue;
			int p=find(e[i].x);
			int q=find(e[i].y);
			if (p!=q)
			{
				f[p]=q;
				ans+=e[i].w;
				cnt++;
			}
		}
		if (cnt!=n-1) printf("oh!\n");
		else printf("%.1lf\n",ans*100.0);
	}
	return 0;
}