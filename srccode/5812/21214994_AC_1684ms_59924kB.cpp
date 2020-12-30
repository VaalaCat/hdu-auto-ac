#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <complex>
#include <bitset>
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define defor(i,a,b) for(int i=a;i>=b;--i)
#define infor(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
template <class _E> inline void read(_E &e){
	e=0;bool ck=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')ck=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){e=e*10+ch-'0';ch=getchar();}
	if(ck)e=-e;
}
const int N=1000005;
int pri[N],cnt[N],tot,vis[N];
inline void shaipri(){
	for(int i=2;i<=1000000;++i){
		if(!vis[i]){pri[++tot]=i;vis[i]=i;}
		for(int j=1;i*pri[j]<=1000000;++j){
			vis[i*pri[j]]=pri[j];
			if(i%pri[j]==0)break;
		}
	}
	for(int i=1;i<=1000000;++i){
		int x=i;
		while(x){
			if(x==1)break;
			int t=vis[x];
			while(x%t==0)x/=t,cnt[i]++;
		}
	}
}
multiset <int> s[N];
multiset <int> :: iterator it;
bitset <N> b;
int sum;
int n;
int ans;

int main(){
	shaipri();int Case=1;
	while(scanf("%d",&n)==1&&n){
		sum=0;
		printf("Case #%d:\n",Case++);
		for(int i=1;i<=1000000;++i)s[i].clear();
		b.reset();
		while(n--){
			char op[3];scanf("%s",op);
			int y;
			if(op[0]=='I'){
				read(y);if(b[y])continue;b[y]=1;sum++;
				for(int i=1;i*i<y;++i){
					if(y%i)continue;
					s[i].insert(cnt[y/i]);
					s[y/i].insert(cnt[i]);
				}
				int j=sqrt(y);
				if(j*j==y){
					s[j].insert(cnt[j]);
				}
			}
			if(op[0]=='D'){
				read(y);if(b[y]==0)continue;b[y]=0;sum--;
				for(int i=1;i*i<y;++i){
					if(y%i)continue;
					it=s[i].find(cnt[y/i]);
					if(it!=s[i].end())s[i].erase(it);
					it=s[y/i].find(cnt[i]);
					if(it!=s[y/i].end())s[y/i].erase(it);
				}
				int j=sqrt(y);
				if(j*j==y){
					it=s[j].find(cnt[j]);
					if(it!=s[j].end())s[j].erase(it);
				}
			}
			if(op[0]=='Q'){
				ans=inf;int x;
				read(x);if(sum==0){puts("-1");continue;}
				for(int i=1;i*i<=x;++i){
					if(x%i)continue;
					int tmp=min(cnt[i]+(s[x/i].empty()?inf:*s[x/i].begin()),cnt[x/i]+(s[i].empty()?inf:*s[i].begin()));
					ans=min(ans,tmp);
				}
				printf("%d\n",ans==inf?-1:ans);
			}
		}
	}
	return 0;
}