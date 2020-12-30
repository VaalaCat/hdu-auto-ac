#include <cstdio>
#include <iostream> 
#include <cstring>
using namespace std;
int a[5005];
int cnt;
int n;

int main()
{
	while (scanf("%d",&n)!=EOF)
	{
		int ans=999999999;
		memset(a,0,sizeof a);
		cnt=0;
		for (int i=0;i<n;i++) scanf("%d",&a[i]);
		for (int i=0;i<n;i++)
		{
			for (int j=i+1;j<n;j++)
			{
				if (a[i]>a[j])
				{
					cnt++;
				}
			}
		}
		ans=min(ans,cnt);
		for (int i=0;i<n;i++) 
		{
			cnt=cnt-a[i]+n-a[i]-1;
			ans=min(ans,cnt);
		}
		printf("%d\n",ans);
	}
	return 0;
}