#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=1e6+10,MAXM=3e5+10;
const int MOD=1e9+7;
const ll llINF=((1ll<<61));

int n,m;
int a[MAXN],b[MAXN],_next[MAXN];

void get_fail()
{
    for(int i=2;i<=n;i++)
    {
        int u=_next[i-1];
        while(u&&b[u]!=b[i])u=_next[u];
        _next[i]=u+1;
    }
}

int AC()
{
    int u=0;
    for(int i=1;i<=n;i++)
    {
        while(u&&b[u+1]!=a[i])u=_next[u];
        if(b[u+1]==a[i])
        u++;
        if(u>=m)
            return i-m+1;
        //cout<<u<<" "<<i<<endl;
    }
    return -1;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=m;i++)scanf("%d",&b[i]);
        get_fail();
        printf("%d\n",AC());
    }
    return 0;
}
