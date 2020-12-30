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
#define ls id<<1
#define rs id<<1|1
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll mod=1e9+7;
template <class _E> inline void read(_E &e){
	e=0;bool ck=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')ck=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){e=e*10+ch-'0';ch=getchar();}
	if(ck)e=-e;
}
int n,ans;
ll sum;
int a[200050];
ll s[200050];

int main(){
	while(scanf("%d",&n)==1){
		ans=0;sum=0;
		int pos=0;
		for(int i=0;i<=n;++i)read(a[i]),s[i]=s[i-1]+a[i];
		for(int i=1;i<=n;++i){
			if(a[i]>=i){
				sum=0;ans=i;continue;
			}
			else{
				sum+=a[i];
				while(sum>ans){
					ans++;sum-=a[ans];
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}