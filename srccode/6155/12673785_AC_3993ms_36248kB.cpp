#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const ll mod=1e9+7;
const int N=100050;
template <class _E> inline void read(_E &e){
	e=0;bool ck=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')ck=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){e=(e<<1)+(e<<3)+ch-'0';ch=getchar();}
	if(ck)e=-e;
}
int n,m;
struct Matrix{
	ll a[3][3];
	friend Matrix operator * (const Matrix &x,const Matrix &y){
		Matrix ret;
		for (int i=0;i<3;++i)
			for (int j=0;j<3;++j){
				ret.a[i][j]=0;
				for (int k=0;k<3;++k)
					ret.a[i][j]+=x.a[i][k]*y.a[k][j],ret.a[i][j]%=mod;
				ret.a[i][j]%=mod;
			}
		return ret;
	}
}m0,m1,m2;
void init_m(){
	m0.a[0][0]=1;m0.a[0][1]=0;m0.a[0][2]=0;
	m0.a[1][0]=1;m0.a[1][1]=1;m0.a[1][2]=0;
	m0.a[2][0]=1;m0.a[2][1]=0;m0.a[2][2]=1;
	m1.a[0][0]=1;m1.a[0][1]=1;m1.a[0][2]=0;
	m1.a[1][0]=0;m1.a[1][1]=1;m1.a[1][2]=0;
	m1.a[2][0]=0;m1.a[2][1]=1;m1.a[2][2]=1;
	m2.a[0][0]=1;m2.a[0][1]=0;m2.a[0][2]=0;
	m2.a[1][0]=0;m2.a[1][1]=1;m2.a[1][2]=0;
	m2.a[2][0]=0;m2.a[2][1]=0;m2.a[2][2]=1;
}

#define ls id<<1
#define rs id<<1|1
char a[N];
struct seg{
	int l,r,rev;
	Matrix mat;
}t[N<<2];
inline void rever(Matrix &tmp){
	swap(tmp.a[0][0],tmp.a[0][1]);
	swap(tmp.a[1][0],tmp.a[1][1]);
	swap(tmp.a[2][0],tmp.a[2][1]);
	swap(tmp.a[0][0],tmp.a[1][0]);
	swap(tmp.a[0][1],tmp.a[1][1]);
}
inline void pushup(int id){
	t[id].mat=t[ls].mat*t[rs].mat;
}
inline void pushdown(int id){
	if (t[id].rev){
		t[ls].rev^=1;t[rs].rev^=1;
		rever(t[ls].mat);rever(t[rs].mat);
		t[id].rev=0;
	}
}
void build(int l,int r,int id){
	t[id].l=l,t[id].r=r;
	t[id].rev=0;
	if (l==r){
		t[id].mat=((a[l]-'0')==1)?m1:m0;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,ls);build(mid+1,r,rs);
	pushup(id);
}
void change(int L,int R,int id){
	int l=t[id].l,r=t[id].r;
	if (l>=L&&r<=R){
		t[id].rev^=1;
		rever(t[id].mat);
		return;
	}
	pushdown(id);
	if (r<L||l>R) return;
	int mid=(l+r)>>1;
	if (R<=mid) change(L,R,ls);
	else if (L>mid) change(L,R,rs);
	else{
		change(L,mid,ls);
		change(mid+1,R,rs);
	}
	pushup(id);
}
Matrix querydp(int L,int R,int l,int r,int id){
	if (l>=L&&r<=R) return t[id].mat;
	if (l>R||r<L) return m2;
	int mid=(l+r)>>1;
	pushdown(id);
	return querydp(L,R,l,mid,ls)*querydp(L,R,mid+1,r,rs);
}

int main(){
	init_m();
	int Test;scanf("%d",&Test);
	while (Test--){
		memset(t,0,sizeof t);
		read(n),read(m);
		scanf("%s",a+1);
		build(1,n,1);
		while(m--){
			int op,l,r;
			read(op),read(l),read(r);
			if (op==1) change(l,r,1);
			else{
				Matrix ans=querydp(l,r,1,n,1);
				printf("%lld\n",(ans.a[2][0]+ans.a[2][1])%mod);
			}
		}	
	}
	
	return 0;
}