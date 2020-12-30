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
const int N=100050;
int n,Q;
int t[N];
inline int lowbit(int x){return x&(-x);}
inline void upd(int x,int val){while(x<=n){t[x]+=val;x+=lowbit(x);}}
inline int query(int x){int ret=0;while(x){ret+=t[x];x-=lowbit(x);}return ret;}
int a[N];
int ans[N];
struct querys{
	int l,r;
	int id;
}q[N];
int block[N];
inline void data_init(){
	mem(t,0);mem(ans,0);mem(block,0);
}
inline bool cmp(const querys &x,const querys &y){
	if(block[x.l]==block[y.l])return x.r<y.r;
	return block[x.l]<block[y.l];
}
inline int cal(int k){
	int L=1,R=n,ret=0;
	int l=q[k].l,r=q[k].r,len=r-l+1;
	while(L<=R){
		int mid=(L+R)>>1;
		if(len-query(mid-1)>=mid)ret=mid,L=mid+1;
		else R=mid-1;
	}
	return ret;
}

int main(){
	while(scanf("%d%d",&n,&Q)==2){
		data_init();
		for(int i=1;i<=n;++i)read(a[i]);
		int t=sqrt(n);
		for(int i=1;i<=n;++i)block[i]=(i-1)/t;
		for(int i=1;i<=Q;++i){
			read(q[i].l),read(q[i].r);
			q[i].id=i;
		}
		sort(q+1,q+Q+1,cmp);
		int L=1,R=0;
		for(int k=1;k<=Q;++k){
			while(R>q[k].r){
				upd(a[R],-1);
				R--;
			}
			while(R<q[k].r){
				R++;
				upd(a[R],1);
			}
			while(L<q[k].l){
				upd(a[L],-1);
				L++;
			}
			while(L>q[k].l){
				L--;
				upd(a[L],1);
			}
			ans[q[k].id]=cal(k);
		}
		for(int i=1;i<=Q;++i)printf("%d\n",ans[i]);
	}
	return 0;
}