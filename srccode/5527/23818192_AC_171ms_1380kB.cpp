#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
ll p;
int ans;
ll val[]={0,1,5,10,20,50,100,200,500,1000,2000};
ll c[15];
ll s[15];
void dfs(int nowp,int used,int step)
{
    if(nowp<0)return;
    if(step==0)
    {
        if(nowp==0)ans=max(ans,used);
        return;
    }
    ll tmp=nowp-s[step-1];
    if(tmp<0)tmp=0;
    int t=tmp/val[step]+(tmp%val[step]>0);
    if(t>c[step])return;
    dfs(nowp-t*val[step],used+t,step-1);
    t++;
    if(t>c[step])return;
    dfs(nowp-t*val[step],used+t,step-1);
}

int main()
{
    int Test;scanf("%d",&Test);
    while(Test--)
    {
        mem(s,0);ans=0;
        scanf("%lld",&p);
        for(int i=1;i<=10;++i)scanf("%lld",&c[i]);
        for(int i=1;i<=10;++i)s[i]=s[i-1]+c[i]*val[i];
        dfs(p,0,10);
        printf("%d\n",(ans==0)?-1:ans);
    }
    return 0;
}
