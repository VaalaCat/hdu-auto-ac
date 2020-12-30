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
char s[105][105];
int dx[]={1,1,0,0,1,-1,-1,-1};
int dy[]={1,-1,1,-1,0,0,-1,1};
void dfs(int x,int y){
    s[x][y]='*';
    for(int k=0;k<8;++k){
        int nx=x+dx[k];
        int ny=y+dy[k];
        if(s[nx][ny]!='@')continue;
        dfs(nx,ny);
    }
}

int main(){
    while(scanf("%d%d",&n,&m)==2&&n+m){
        int tot=0;
        for(int i=1;i<=n;++i){
            scanf("%s",s[i]+1);
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(s[i][j]=='@'){
                    tot++;dfs(i,j);
                }
            }
        }
        printf("%d\n",tot);
    }
    return 0;
}
