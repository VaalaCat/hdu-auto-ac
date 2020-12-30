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
int n,m,t;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
char s[2][15][15];
int sk,sx,sy,ek,ex,ey;
bool vis[20000];
int d[20000];
inline int id(int k,int x,int y){
    return k*10000+x*100+y;
}

void bfs(){
    queue <int> q;int nk;
    mem(vis,0);mem(d,inf);
    d[id(sk,sx,sy)]=0;
    q.push(id(sk,sx,sy));
    while(!q.empty()){
        int u=q.front();q.pop();vis[u]=0;
        if(d[u]>t)continue;
        int uk=u/10000,ux=(u-10000*uk)/100,uy=u%100;
        for(int k=0;k<4;++k){
            nk=uk;
            int nx=ux+dx[k];
            int ny=uy+dy[k];
            if(s[nk][nx][ny]!='.'&&s[nk][nx][ny]!='P'&&s[nk][nx][ny]!='#')continue;
            if(s[nk][nx][ny]=='#'){
                if(s[nk^1][nx][ny]=='*'||s[nk^1][nx][ny]=='#')continue;
                if(d[id(nk^1,nx,ny)]>d[id(uk,ux,uy)]+1){
                    d[id(nk^1,nx,ny)]=d[id(uk,ux,uy)]+1;
                    if(!vis[id(nk^1,nx,ny)]){
                        vis[id(nk^1,nx,ny)]=1;
                        q.push(id(nk^1,nx,ny));
                    }
                }
                continue;
            }
            if(d[id(nk,nx,ny)]>d[id(uk,ux,uy)]+1){
                d[id(nk,nx,ny)]=d[id(uk,ux,uy)]+1;
                if(!vis[id(nk,nx,ny)]){
                    vis[id(nk,nx,ny)]=1;
                    q.push(id(nk,nx,ny));
                }
            }
        }
    }
}

int main(){
    int Test;read(Test);
    while(Test--){
        read(n),read(m),read(t);
        for(int k=0;k<2;++k){
            for(int i=1;i<=n;++i){
                scanf("%s",s[k][i]+1);
                for(int j=1;j<=m;++j){
                    if(s[k][i][j]=='S')sk=k,sx=i,sy=j;
                    if(s[k][i][j]=='P')ek=k,ex=i,ey=j;
                }
            }
        }
        bfs();
        if(d[id(ek,ex,ey)]>t)puts("NO");
        else puts("YES");
    }
    return 0;
}
