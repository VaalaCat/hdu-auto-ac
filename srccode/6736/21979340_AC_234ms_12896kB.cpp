#include <bits/stdc++.h>
#define ll long long
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const ll mod=998244353LL;
int n,m;
ll ans;
const int N=300050;
struct edge
{
    int v,nxt;
}e[(N+200000)*2];
int head[N],etot,dfn[N],tim;
ll sum;
int tot;
int siz[N];
int sta[N],top;
inline void ad(int u,int v)
{
    e[++etot].v=v;e[etot].nxt=head[u];head[u]=etot;
}
int dfs(int u,int fa)
{
    dfn[u]=++tim;
    int lowu=tim;
    for(int i=head[u];i;i=e[i].nxt)
    {
        int v=e[i].v;
    	if(!dfn[v])
        {
            sta[++top]=v;
            int lowv=dfs(v,u);
            lowu=min(lowu,lowv);
            if(lowv>=dfn[u])
            {
                tot++;
                while(sta[top]!=v)top--,siz[tot]++;
                top--;siz[tot]+=2;
            }
        }
        else if(v!=fa)
        {
        	lowu=min(lowu,dfn[v]);
		}
    }
    return lowu;
}

inline ll mi(ll a,ll b)
{
    ll ret=1;
    while(b)
    {
        if(b&1)ret=(ret*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ret%mod;
}

int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        etot=0;tot=0;sum=0;tim=0;top=0;ans=1;
        mem(head,0);mem(siz,0);mem(dfn,0);
        for(int i=1;i<=m;++i)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            ad(x,y),ad(y,x);
        }
        for(int i=1;i<=n;++i)
        {
        	if(!dfn[i])
            {
                sta[top=1]=i;
                dfs(i,i);
            }
		}
        for(int i=1;i<=tot;++i)
        {
//            cout<<vec[i].size()<<endl;
            if(siz[i]>2)
            {
                sum+=siz[i];
                ans*=(mi(2,siz[i])-1);
                ans=(ans+mod)%mod;
            }
        }
//        printf("%d\n",sum);
        ans*=mi(2,max(0LL,m-sum));ans%=mod;
        printf("%lld\n",ans);
    }
    return 0;
}