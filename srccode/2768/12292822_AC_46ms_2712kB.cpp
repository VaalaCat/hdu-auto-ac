#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <climits>
#include <cctype>
#include <cstdlib>
#define ll long long
#define llmax LONG_LONG_MAX
#define llmin LONG_LONG_MIN
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
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
int a[505][505];
bool used[505];
int link[505];
int c,d,v,ans;
int n1,n2;
bool find(int u)
{
	for (int i=1;i<=n2;++i)
	{
		if (!used[i] && a[u][i])
		{
			used[i]=1;
			if (link[i]==-1 || find(link[i]))
			{
				link[i]=u;
				return true;
			}
		}
	}
	return false;
}

struct people{
	int cat;
	int dog;
}p1[505],p2[505];

int main()
{
	int Test;
	read(Test);
	while (Test--)
	{
		memset(a,0,sizeof a);
		memset(link,-1,sizeof link);
		n1=n2=ans=0;
		read(c),read(d),read(v);
		for (int i=1;i<=v;++i)
		{
			char t1,t2;int d1,d2;
			scanf(" %c%d %c%d",&t1,&d1,&t2,&d2);
			if (t1=='D')
			{
				p1[++n1].cat=d1;
				p1[n1].dog=d2;
			}
			else
			{
				p2[++n2].cat=d2;
				p2[n2].dog=d1;
			}
		}
		for (int i=1;i<=v;++i)
		{
			for (int j=1;j<=v;++j)
			{
				if (p1[i].cat==p2[j].cat || p1[i].dog==p2[j].dog)
				{
					a[i][j]=1;
				}
			}
		}
		for (int i=1;i<=n1;++i)
		{
			memset(used,0,sizeof used);
			if (find(i)) ++ans;
		}
		cout<<v-ans<<endl;
	}
	return 0;
}