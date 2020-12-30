#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;
int n,m,k;
int a[100005];
deque <int> q1,q2;
int ans;

int main()
{
	while (~scanf("%d%d%d",&n,&m,&k))
	{
		while (!q1.empty()) q1.pop_back();
		while (!q2.empty()) q2.pop_back();
		ans=0;
		int last=0;
		for (int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		for (int i=1;i<=n;++i)
		{
			while (!q1.empty() && a[i]>a[q1.back()])
				q1.pop_back();
			while (!q2.empty() && a[i]<a[q2.back()])
				q2.pop_back();
			q1.push_back(i),q2.push_back(i);
			while (!q1.empty() && a[q1.front()]-a[q2.front()]>k)
			{
				if (q1.front()>q2.front())
				{
					last=q2.front();
					q2.pop_front();
				}
				if (q1.front()<q2.front())
				{
					last=q1.front();
					q1.pop_front();
				}
			}
			if (!q1.empty() && !q2.empty() && a[q1.front()]-a[q2.front()]>=m)
				ans=max(ans,i-last);
		}
		cout<<ans<<endl;
	}
	return 0;
}