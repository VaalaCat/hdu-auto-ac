#include <bits/stdc++.h>
#define ll long long
#define ls id << 1
#define rs id << 1 | 1
#define mem(array, value, size, type) memset(array, value, ((size) + 5) * sizeof(type))
#define memarray(array, value) memset(array, value, sizeof(array))
#define pb(x) push_back(x)
#define st(x) (1LL << (x))
#define pii pair<int, int>
using namespace std;
const int N = 3000500;
const int inf = 0x3f3f3f3f;
const ll mod = 998244353LL;
clock_t TIME_START, TIME_END;
void program_end()
{
#ifdef ONLINE
    printf("\nTime used: %.6lf(s)\n", ((double)TIME_END - TIME_START) / CLOCKS_PER_SEC);
    system("pause");
#endif
}
int pri[N], vis[N], tot, is[N];
int ans[N];
void Init()
{
    for (int i = 2; i < N; ++i)
    {
        if (!vis[i])
            vis[i] = 1, pri[++tot] = i, is[i] = 1;
        for (int j = 1; j <= tot && i * pri[j] < N; ++j)
        {
            vis[i * pri[j]] = 1;
            if (i % pri[j] == 0)
                break;
        }
    }
    for (int i = 10, j = 1; i < N; i += 3, ++j)
        ans[j] = ans[j - 1] + is[i];
}

void solve()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", ans[n]);
}

int main()
{
    TIME_START = clock();
    int Test = 1;
    Init();
    cin >> Test;
    while (Test--)
        solve();
    TIME_END = clock();
    program_end();
    return 0;
}