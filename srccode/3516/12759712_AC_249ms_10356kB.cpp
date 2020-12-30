#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <cctype>
using namespace std;
typedef long long ll;
const int N=1050;
const int inf=0x3f3f3f3f;
int n;
int x[N],y[N];
int dp[N][N],s[N][N];

inline int cost(int i,int j,int k){
	if (k>=j) return inf;
	return x[k+1]-x[i]+y[k]-y[j];
}

int main(){
	while(~scanf("%d",&n)){
		memset(dp,0,sizeof dp);
		memset(s,0,sizeof s);
		for (int i=1;i<=n;++i) cin>>x[i]>>y[i];
		for (int i=1;i<=n;++i) s[i][i]=i;
		for (int l=2;l<=n;++l){
			for (int i=1;i+l-1<=n;++i){
				int j=i+l-1;dp[i][j]=inf;
				for (int k=s[i][j-1];k<=s[i+1][j];++k){
					if (dp[i][k]+dp[k+1][j]+cost(i,j,k)<dp[i][j])
						dp[i][j]=dp[i][k]+dp[k+1][j]+cost(i,j,k),s[i][j]=k;
				}
			}
		}
		cout<<dp[1][n]<<endl;
	}
	return 0;
}