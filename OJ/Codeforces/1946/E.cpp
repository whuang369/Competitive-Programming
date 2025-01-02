#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
const ll MOD = 1e9 + 7;
ll n, m1, m2, a[N], b[N], pw[N], inv[N];
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
    pw[0] = 1;
    for (ll i = 1; i <= N - 5; i ++)
        pw[i] = pw[i - 1] * i % MOD;
    inv[N - 5] = ksm (pw[N - 5], MOD - 2);
    for (ll i = N - 5; i >= 1; i --)
        inv[i - 1] = inv[i] * i % MOD;
    // cout << pw[N - 5] * inv[N - 5] % MOD << " " << inv[1] << "\n";
}
ll C (ll x, ll y) {
    return pw[x] * inv[y] % MOD * inv[x - y] % MOD;
}
void solve () {
    cin >> n >> m1 >> m2;
    for (int i = 1; i <= m1; i ++)
        cin >> a[i];
    for (int i = 1; i <= m2; i ++)
        cin >> b[i];
    if (a[1] != 1 || a[m1] != b[1] || b[m2] != n) {
        cout << "0\n";
        return ;
    }
    ll ans = C(n - 1, a[m1] - 1);
    for (int i = m1 - 1; i >= 1; i --) {
        ans *= C(a[i + 1] - 2, a[i] - 1);
        ans %= MOD;
        ans *= pw[a[i + 1] - 1 - a[i]];
        ans %= MOD;
    }
    ans *= pw[a[1] - 1];
    ans %= MOD;
    for (int i = 2; i <= m2; i ++) {
        ans *= C(n - b[i - 1] - 1, b[i] - b[i - 1] - 1);
        ans %= MOD;
        ans *= pw[b[i] - b[i - 1] - 1];
        ans %= MOD;
    }
    cout << ans << "\n";
}
int main () {
    init ();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve ();
    }
    return 0;
}