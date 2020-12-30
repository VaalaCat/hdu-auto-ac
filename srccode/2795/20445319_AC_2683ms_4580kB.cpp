//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/hash_policy.hpp>
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
#define mem(a,b) memset(a,b,sizeof(a))
#define defor(i,a,b) for(int i=a;i>=b;--i)
#define infor(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
//using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod=1e9+7;
const int INF=0x3f3f3f3f;
template <class _E> inline void read(_E &e){
	e=0;bool ck=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')ck=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){e=e*10+ch-'0';ch=getchar();}
	if(ck)e=-e;
}
const int N=200050;
int h,w,n;
int a[N];
struct segtree{
	int maxn;
}t[N<<2];
inline void data_init(){
	mem(t,0);
}
inline void pushup(int id){t[id].maxn=max(t[ls].maxn,t[rs].maxn);}
void build(int l,int r,int id){
	t[id].maxn=w;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(l,mid,ls);
	build(mid+1,r,rs);
	pushup(id);
}
int query(int l,int r,int id,int val){
	if(l==r){
		t[id].maxn-=val;
		return l;
	}
	int mid=(l+r)>>1;
	int ret;
	if(t[ls].maxn>=val)ret=query(l,mid,ls,val);
	else ret=query(mid+1,r,rs,val);
	pushup(id);
	return ret;
}

int main(){
	while(scanf("%d%d%d",&h,&w,&n)==3){
//		data_init();
		h=min(h,n);
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
		}
		build(1,h,1);
		for(int i=1;i<=n;++i){
			if(a[i]>t[1].maxn){
				puts("-1");
				continue;
			}
			printf("%d\n",query(1,h,1,a[i]));
		}
	}
	return 0;
} 