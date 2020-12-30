
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <utility>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000") 
#define eps 1e-10
#define inf 0x3f3f3f3f
#define PI pair<int, int> 
typedef long long LL;
const int maxn = 1000 + 5;
struct node{
	int cost, w;
	bool operator < (const node& p) const {
		return cost < p.cost;
	}
}a[maxn];
 
int main() {
	int T, n, m;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &m, &n);
		for(int i = 0; i < n; ++i) scanf("%d%d", &a[i].cost, &a[i].w);
		sort(a, a+n);
		double ans = 0;
		for(int i = 0; i < n; ++i) {
			if(m > a[i].cost * a[i].w) {
				ans += a[i].w;
				m -= a[i].cost * a[i].w;
			}
			else {
				ans += 1.0 * m / a[i].cost;
				break;
			}
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}