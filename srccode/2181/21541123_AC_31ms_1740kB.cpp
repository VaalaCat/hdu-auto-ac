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
int mp[25][25];
int tot;
int m;
int walk[25];
bool vis[25];
void dfs(int u,int step){
    walk[step]=u;
    if(step<20&&u==m&&step!=0)return;
    if(step==20&&u==m){
        printf("%d:  ",++tot);
        for(int i=0;i<20;++i){
            printf("%d ",walk[i]);
        }
        printf("%d\n",walk[20]);
        return;
    }
    for(int i=1;i<=20;++i){
        if(!mp[u][i])continue;
        if(vis[i]&&i!=m)continue;
        vis[i]=1;
        dfs(i,step+1);
        vis[i]=0;
    }
}

int main(){
    for(int i=1;i<=20;++i){
        int k[3];
        for(int j=0;j<3;++j)read(k[j]);
        for(int j=0;j<3;++j)mp[k[j]][i]=mp[i][k[j]]=1;
    }
    while(scanf("%d",&m)==1&&m){
        tot=0;walk[20]=m;
        dfs(m,0);
    }
    return 0;
}
