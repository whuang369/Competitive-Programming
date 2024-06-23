#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e5 + 5;
const ll MOD = 1e9 + 7;
int n, k;
ll p[N], rev[N];
ll ksm (ll x, ll y) {
    ll ret = 1, now = x;
    while (y) {
        if (y & 1) {
            ret *= now;
            ret %= MOD;
        }
        now *= now;
        now %= MOD;
        y >>= 1;
    }
    return ret;
}
void init () {
    p[0] = 1;
    for (ll i = 1; i <= N - 5; i ++)
        p[i] = p[i - 1] * i % MOD;
    rev[N - 5] = ksm (p[N - 5], MOD - 2);
    for (ll i = N - 6; i >= 1; i --)
        rev[i] = rev[i + 1] * (i + 1) % MOD;
    rev[0] = 1;
}
ll C (ll n, ll m) {
    return p[n] * rev[m] % MOD * rev[n - m] % MOD;
}
void solve () {
    cin >> n >> k;
    ll m = n;
    for (int i = 0; i < k; i ++) {
        int x, y;
        cin >> x >> y;
        if (x != y)
            m -= 2;
        else
            m --;
    }
    ll ans = 0;
    for (ll i = 0; i <= m; i += 2) {
        ans += p[i] * C(m, i) % MOD * rev[i / 2] % MOD;
        ans %= MOD;
    }
    cout << ans << "\n";
}
int T;
int main () {
    init ();
    ios::sync_with_stdio (false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T --) {
        solve ();
    }
}