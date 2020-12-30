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
int n,q;
struct node{
	int val;
	int id;
	bool operator < (const node &x)const{
		return val<x.val;
	}
}a[N];
int has[N];
struct chair{
	int l,r;
	int sum;
}t[N*65];
int tot,rt[N];
inline void init_tree(){t[0].l=t[0].r=t[0].sum=tot=0;}
void build(int l,int r,int &id,int val){
	t[++tot]=t[id];id=tot;
	t[id].sum++;
	if(l==r)return;
	int mid=(l+r)>>1;
	if(val<=mid)build(l,mid,t[id].l,val);
	else build(mid+1,r,t[id].r,val);
}
int query(int i,int j,int L,int R,int k){
	if(L==R)return L;
	int d=t[t[j].l].sum-t[t[i].l].sum;
	int mid=(L+R)>>1;
	if(k<=d)return query(t[i].l,t[j].l,L,mid,k);
	else return query(t[i].r,t[j].r,mid+1,R,k-d);
}

int main(){
	while(scanf("%d%d",&n,&q)==2){
		init_tree();
		for(int i=1;i<=n;++i)read(a[i].val),a[i].id=i;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;++i)has[a[i].id]=i;
		for(int i=1;i<=n;++i){
			rt[i]=rt[i-1];
			build(1,n,rt[i],has[i]);
		}
		while(q--){
			int l,r;read(l),read(r);
			int L=0,R=r-l+1,ans=0;
			while(L<=R){
				int mid=(L+R)>>1;
				if(a[query(rt[l-1],rt[r],1,n,r-l+1-mid+1)].val>=mid)ans=max(ans,mid),L=mid+1;
				else R=mid-1;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}