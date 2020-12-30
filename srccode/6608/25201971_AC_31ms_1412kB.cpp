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
const int N = 10000050;
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
ll p;
int prime[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
const int S = 5;
ll qmul(ll a, ll b, ll c)
{
    ll ans = 0;
    a %= c, b %= c;
    while (b)
    {
        if (b & 1)
        {
            ans += a;
            if (ans > c)
                ans -= c;
        }
        a <<= 1;
        if (a > c)
            a -= c;
        b >>= 1;
    }
    return ans;
}
ll qpow(ll a, ll b, ll c)
{
    ll ans = 1;
    a %= c;
    while (b)
    {
        if (b & 1)
            ans = qmul(ans, a, c);
        a = qmul(a, a, c);
        b >>= 1;
    }
    return ans;
}
bool check(ll a, ll n, ll x, ll t)
{
    ll ans = qpow(a, x, n);
    ll last = ans;
    for (int i = 1; i <= t; ++i)
    {
        ans = qmul(ans, ans, n);
        if (ans == 1 && last != i && last != n - 1)
            return true;
        last = ans;
    }
    return ans != 1;
}
bool Miller_Rabin(ll n)
{
    if (n < 2)
        return false;
    if (n == 2 || n == 3 || n == 5 || n == 7)
        return true;
    if ((n & 1) == 0)
        return false;
    ll x = n - 1, t = 0;
    srand(time(NULL));
    for (int i = 0; i < S; ++i)
    {
        ll a = rand() % (n - 1) + 1;
        if (check(a, n, x, t))
            return false;
    }
    return true;
}

void solve()
{
    ll ans = 1;
    scanf("%lld", &p);
    for (ll i = p - 2; i > 1; --i)
    {
        if (Miller_Rabin(i))
        {
            break;
        }
        ans = qmul(ans, qpow(i, p - 2, p), p);
    }
    printf("%lld\n", ans);
}

int main()
{
    TIME_START = clock();
    int Test = 1;
    cin >> Test;
    while (Test--)
        solve();
    TIME_END = clock();
    program_end();
    return 0;
}