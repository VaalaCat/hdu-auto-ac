#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
ll d[21];
int n;

int main()
{
	while (scanf("%d",&n)==1)
	{
		memset(d,0,sizeof d);
		d[1]=0,d[2]=1;
		for (int i=3;i<=n;i++)
		{
			d[i]=(i-1)*(d[i-1]+d[i-2]);
		}
		printf("%lld\n",d[n]);
	}
	return 0;
} 