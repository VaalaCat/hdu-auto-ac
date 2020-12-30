#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#define ll long long
using namespace std;
int n;
ll A,B;

int main()
{
	while (~scanf("%d%lld%lld",&n,&A,&B))
	{
		ll ans=1,tmp=1;
		deque <pair<int,ll> > q;
		for (int i=1;i<=n;++i)
		{
			tmp*=A,tmp%=B;
			while (!q.empty() && q.back().second>=tmp)
				q.pop_back();
			q.push_back(make_pair(i,tmp));
			while (!q.empty() && q.front().first<i-A)
				q.pop_front();
			ans*=q.front().second;
			ans%=B;
		}
		cout<<ans<<endl;
	}
	return 0;
}