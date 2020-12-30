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
#include <bitset>
#define ls id<<1
#define rs id<<1|1
using namespace std;
typedef long long ll;
template <class _E> inline void read(_E &e){
	e=0;bool ck=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')ck=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){e=e*10+ch-'0';ch=getchar();}
	if(ck)e=-e;
}
int T,n;
int a[500005];
bitset <1005> is;

void shai(){
	for(int i=1;i<=250000;++i)
		for(int j=i*2;j<=500000;j+=i)
			a[j]+=i;
	for(int i=1;i<=500000;++i){
		if(a[i]>1000)continue;
		is[a[i]]=1;
	}
}

int main(){
	read(T);
	shai();
	while(T--){
		read(n);
		is[n]?printf("no\n"):printf("yes\n");
	}
	return 0;
} 