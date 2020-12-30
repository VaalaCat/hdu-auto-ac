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
typedef long double ld;
const ll mod=1e9+7;
template <class _E> inline void read(_E &e){
	e=0;bool ck=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')ck=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){e=e*10+ch-'0';ch=getchar();}
	if(ck)e=-e;
}
const int N=1050;
int n;
struct dou{
	ld v;
	int id;
}p[N];
inline bool cmp(const dou &x,const dou &y){
	if(x.v==y.v)return x.id<y.id;
	return x.v<y.v;
}

int main(){
	while(scanf("%d",&n)==1){
		for(int i=1;i<=n;++i){
			ld a,b,c;
			cin>>a>>b>>c;
			p[i].id=i;
			p[i].v=(a+b)/(a+b+c);
		}
		sort(p+1,p+n+1,cmp);
		for(int i=1;i<n;++i)printf("%d ",p[i].id);
		cout<<p[n].id<<endl;
	}
	return 0;
}