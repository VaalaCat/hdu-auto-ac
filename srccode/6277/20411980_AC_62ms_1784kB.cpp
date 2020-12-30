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
ll n,a;

int main(){
	while(scanf("%lld%lld",&n,&a)==2){
		cout<<(a+n)/2<<endl;
	}
	return 0;
}