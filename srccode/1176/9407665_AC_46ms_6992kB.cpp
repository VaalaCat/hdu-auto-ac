#include<stdio.h>
#include<string.h>
int dp[14][100010];
int max(int a,int b)
{
return a>b?a:b;
}
int main()
{
int n,t,i,j,tt,x;
    while(scanf("%d",&n)&&n)
{
tt=0;
memset(dp,0,sizeof(dp));
while(n--)
{
scanf("%d%d",&x,&t);
dp[x+1][t]++;
tt=max(t,tt);
}
for(i=tt-1;i>=0;i--)
{
for(j=1;j<=11;j++)
{
dp[j][i]=max(dp[j][i+1],max(dp[j+1][i+1],dp[j-1][i+1]))+dp[j][i];
}
}
printf("%d\n",dp[6][0]);
}
return 0;
}