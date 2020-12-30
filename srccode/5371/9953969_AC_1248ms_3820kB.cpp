#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define me(a) (memset(a,0,sizeof a))
using namespace std;
int n;
int a[100005];
int p[200005];
int s[200005];
int kase;
void malache()
{
	int maxr=0,id=0;
	for (int i=1;i<=n*2+1;i++)
	{
		if (maxr>i) p[i]=min(p[id*2-i],maxr-i);
		else p[i]=1;
		while (s[i+p[i]]==s[i-p[i]]) p[i]++;
		if (maxr<p[i]+i)
		{
			maxr=p[i]+i;
			id=i;
		}
	}
}

void init()
{
	int j=2;
	s[0]=-1,s[1]=-2;
	for (int i=0;i<n;i++)
	{
		s[j++]=a[i];
		s[j++]=-2;
	}
	s[j]=-3;
}

int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		me(p);
		me(a);
		scanf("%d",&n);
		for (int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		init();
		malache();
		int ans=0;
		for (int i=1;i<=2*n+1;i+=2)
		{
			for (int j=p[i]+i-1;j>ans+i;j-=2)
			{
				if (j-i<p[j])
				{
					ans=max(ans,j-i);
					break;
				}
			}
		}
		printf("Case #%d: %d\n",++kase,ans/2*3);
	}
	return 0;
}