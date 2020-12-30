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
ll a,b,c,d;
ll x1[3],x2[3],Y1[3],Y2[3];
ll ans;
int main(){
//	freopen("K.out","w",stdout);
	while(scanf("%lld%lld%lld%lld",&a,&b,&c,&d)==4){
		mem(x1,0),mem(x2,0),mem(Y1,0),mem(Y2,0);
		a--,c--;
		ans=0;
		ll l1=a/2018,r1=b/2018;
		ll L1=a%2018,R1=b%2018;
		ll l2=c/2018,r2=d/2018;
		ll L2=c%2018,R2=d%2018;
		if(L1>=1009)x1[2]++;
		if(R1>=1009)x2[2]++;
		if(L2>=1009)Y1[2]++;
		if(R2>=1009)Y2[2]++;
//		for(int i=2;i<=L1;i+=2)x1[1]++;
		x1[1]=L1/2;x2[1]=R1/2;Y1[1]=L2/2;Y2[1]=R2/2;
//		for(int i=2;i<=R1;i+=2)x2[1]++;
//		for(int i=2;i<=L2;i+=2)Y1[1]++;
//		for(int i=2;i<=R2;i+=2)Y2[1]++;
		x1[0]+=l1,x2[0]+=r1;x1[1]+=l1*1008,x2[1]+=r1*1008;x1[2]+=l1,x2[2]+=r1;
		Y1[0]+=l2,Y2[0]+=r2;Y1[1]+=l2*1008,Y2[1]+=r2*1008;Y1[2]+=l2,Y2[2]+=r2;
		ans+=((x2[0]-x1[0])*(d-c)+(Y2[0]-Y1[0])*(b-a)-(x2[0]-x1[0])*(Y2[0]-Y1[0]));
		ans+=((x2[1]-x1[1])*(Y2[2]-Y1[2])+((x2[2]-x1[2])*(Y2[1]-Y1[1])));
		cout<<ans<<endl;
	}
	return 0;
}