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
int s,n,m;
int gcd(int x,int y){return y==0?x:gcd(y,x%y);}

int main(){
    while(scanf("%d%d%d",&s,&n,&m)==3&&s+n+m){
        s/=gcd(n,m);
        if(s&1){puts("NO");continue;}
        printf("%d\n",s-1);
    }
    return 0;
}
