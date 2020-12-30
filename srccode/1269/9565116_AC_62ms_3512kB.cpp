#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
using namespace std;
const int maxn=10000+10;

int n,m,idx,k=1,cnt;
int head[maxn];
int dfn[maxn],low[maxn];
int ins[maxn],belong[maxn];
stack <int >s;

struct edge
{
    int v,next;
}e[maxn*10];

void adde(int u,int v)
{
     e[k].v=v;
     e[k].next=head[u];
     head[u]=k++;
}

void tarjan(int u)
{
     int v;
     dfn[u]=low[u]=++idx;
     s.push(u);
     ins[u]=1;
     for(int i=head[u];i!=-1;i=e[i].next)
     {
         v=e[i].v;
         if(!dfn[v])
         {
             tarjan(v);
             low[u]=min(low[u],low[v]);
         }
         else if(ins[v])low[u]=min(low[u],dfn[v]);
     }
     if(dfn[u]==low[u])
     {
         cnt++;
         while(u!=v)
         {
             v=s.top();
             s.pop();
             ins[v]=0;
             belong[v]=cnt;
         }
     }
}

void work()
{
     int a,b;
     while(1)
     {
        memset(head,-1,sizeof(head));
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(dfn));
        memset(ins,0,sizeof(dfn));
        memset(belong,0,sizeof(dfn));
        idx=0,cnt=0;
        scanf("%d%d",&n,&m);
        if(n==0&&m==0)break;
        for(int i=1;i<=m;i++)
        {
           scanf("%d%d",&a,&b);
           adde(a,b);
        }
        for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
        if(cnt>1)printf("No\n");
        else printf("Yes\n");
     }
}

int main()
{
    work();
    return 0;
}