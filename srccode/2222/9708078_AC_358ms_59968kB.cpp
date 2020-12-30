#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
using namespace std;
char s[55];
char s1[1000005];
int cnt;
struct Nier_Automata
{
	int ch[500005][26];
	int val[500005];
	int f[500005];
	int last[500005];
	bool vis[500005];
	int sz;
	void init(){sz=1,memset(ch[0],0,sizeof ch[0]),val[0]=f[0]=last[0]=vis[0]=0;}
	int idx(char x)
	{
		return x-'a';
	}
	
	void insert(char *s)
	{
		int n=strlen(s),u=0;
		for (int i=0;i<n;i++)
		{
			int c=idx(s[i]);
			if (!ch[u][c])
			{
				vis[sz]=0;
				ch[u][c]=sz;
				memset(ch[sz],0,sizeof ch[sz]);
				val[sz++]=0;
			}
			u=ch[u][c];
		}
		vis[u]=1;
		val[u]++;
	}
	
	void fail()
	{
		queue <int> q;
		last[0]=f[0]=0;
		for (int i=0;i<26;i++)
		{
			int u=ch[0][i];
			if (u)
			{
				f[u]=last[u]=0;
				q.push(u);
			}
		}
		while (!q.empty())
		{
			int x=q.front();
			q.pop();
			for (int i=0;i<26;i++)
			{
				int u=ch[x][i];
				if (!u) continue;
				q.push(u);
				int v=f[x];
				while (v && !ch[v][i]) v=f[v];
				f[u]=ch[v][i];
				last[u]=val[f[u]]?f[u]:last[f[u]];
			}
		}		
	}
	void print(int i)
	{
		if (val[i])
		{
			if (vis[i])
			{
				cnt+=val[i];
				vis[i]=0;
			}
			print(last[i]);
		}
	}
	
	void find(char s[])
	{
		int n=strlen(s),u=0;
		for (int i=0;i<n;i++)
		{
			int c=idx(s[i]);
			while (u && !ch[u][c]) u=f[u];
			u=ch[u][c];
			if (val[u]) print(u);
			else if (last[u])print(last[u]);		
		}
	}
};

int main()
{
	int t;
	Nier_Automata ac;
	scanf("%d",&t);
	while (t--)
	{
		int n;
		cnt=0;
		ac.init();
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			scanf("%s",s);
			ac.insert(s);
		}
		ac.fail();
		scanf("%s",s1);
		ac.find(s1);
		printf("%d\n",cnt);
	}
	return 0;
}