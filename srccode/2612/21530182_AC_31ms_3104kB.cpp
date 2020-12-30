//#include <bits/extc++.h>
//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <bitset>
#include <vector>
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef long double ld;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
using namespace std;
template <class _E> inline void read(_E &e){
    e=0;bool ck=0;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')ck=1;ch=getchar();}
    while(isdigit(ch)){e=(e<<1)+(e<<3)+ch-'0';ch=getchar();}
    if(ck==1)e=-e;
}
int n,m;
inline int id(int x,int y){
    return (x-1)*m+y;
}
int sx1,sy1,sx2,sy2;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
char s[205][205];
bool vis[40500];
int d1[40500],d2[40500];
struct edge{
    int v,nxt;
}e[100500<<1];
int head[40500],ecnt;
inline void data_init(){
    ecnt=0;mem(head,0);
}
inline void ad(int u,int v){
    e[++ecnt].v=v;e[ecnt].nxt=head[u];head[u]=ecnt;
}
inline void sp1(int node){
    queue <int> q;
    mem(d1,inf);mem(vis,0);
    q.push(node);
    d1[node]=0;
    while(!q.empty()){
        int u=q.front();q.pop();vis[u]=0;
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].v;
            if(d1[v]>d1[u]+1){
                d1[v]=d1[u]+1;
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
}
inline void sp2(int node){
    queue <int> q;
    mem(d2,inf);mem(vis,0);
    q.push(node);
    d2[node]=0;
    while(!q.empty()){
        int u=q.front();q.pop();vis[u]=0;
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].v;
            if(d2[v]>d2[u]+1){
                d2[v]=d2[u]+1;
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
}

int main(){
    while(scanf("%d%d",&n,&m)==2){
        data_init();
        for(int i=1;i<=n;++i){
            scanf("%s",s[i]+1);
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(s[i][j]=='#')continue;
                for(int k=0;k<4;++k){
                    int nx=dx[k]+i;
                    int ny=dy[k]+j;
                    if(s[nx][ny]=='.'||s[nx][ny]=='@'){
                        ad(id(i,j),id(nx,ny));
                    }
                }
            }
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(s[i][j]=='Y'){
                    sx1=i;sy1=j;
                }
                else if(s[i][j]=='M'){
                    sx2=i;sy2=j;
                }
            }
        }
        int ans=inf;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(s[i][j]=='Y'){
                    sp1(id(i,j));
                }
                else if(s[i][j]=='M'){
                    sp2(id(i,j));
                }
            }
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(s[i][j]=='@'){
                    ans=min(ans,d1[id(i,j)]+d2[id(i,j)]);
                }
            }
        }
        printf("%d\n",11*ans);
    }
    return 0;
}
