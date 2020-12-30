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
const double pi=acos(-1.0);
template <class _E> inline void read(_E &e){
	e=0;bool ck=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')ck=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){e=e*10+ch-'0';ch=getchar();}
	if(ck)e=-e;
}
char s[5000000];
double ans[120000];

int main(){
	for(int i=1;i<=110291;++i){
		ans[i]=ans[i-1]+(1.0/(1.0*i*i));
	}
	while(scanf("%s",s)==1){
		int n=strlen(s);
		if(n>=7){
			printf("1.64493\n");
			continue;
		}
		ll num=0;
		for(int i=0;i<n;++i){
			num*=10;
			num+=s[i]-'0';
		}
		if(num>=110292){
			printf("1.64493\n");
			continue;
		}
		printf("%.5lf\n",ans[num]);
	}
	return 0;
}