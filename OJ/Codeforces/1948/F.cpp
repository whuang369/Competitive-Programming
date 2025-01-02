#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e5 + 5, MOD = 998244353;
ll n, a[N], b[N];
ll pw[N], inv[N], pw2[N];
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
    pw2[0] = 1;
    pw2[1] = ksm (2, MOD - 2);
    for (ll i = 2; i <= N - 5; i ++)
        pw[i] = pw[i - 1] * pw[1] % MOD;
    return ;
}
ll C (ll x, ll y) {
    if (x < y)
        return 0;
    return pw[x] * inv[y] % MOD * inv[x - y] % MOD;
}
void solve () {
    ll q;
    cin >> n >> q;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; i ++) {
        cin >> b[i];
        b[i] += b[i - 1];
    }
    while (q --) {
        int l, r;
        cin >> l >> r;
        ll suma = a[r] - a[l - 1], sumb = b[r] - b[r - 1];
        ll suma1 = a[n] - suma, sumb1 = b[n] - sumb;

    }
}
int main () {
    init ();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        solve ();
    }
}