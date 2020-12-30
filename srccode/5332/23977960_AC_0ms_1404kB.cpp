#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int n,m;
int ans[35][35];
ll K;

int main()
{
    int Test;cin>>Test;
    while(Test--)
    {
        mem(ans,0);
        n=30,m=18;
        cin>>K;
        printf("%d %d\n",n,m);
        int p=12;
        for(int i=2;i<=p+1;++i)ans[1][i]=1;
        for(int i=2;i<=p+1;++i)
            for(int j=2;j<=p+1;++j)
                ans[i][j]=1;
        for(int i=p+2;i<n;++i)ans[i][i+1]=1;
        for(int i=1;i<m;++i)
        {
            for(int j=1;j<=K%p;++j)
                ans[1+j][1+p+i]=1;
            K/=p;
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
                printf("%d",ans[i][j]);
            puts("");
        }
    }
    return 0;
}
