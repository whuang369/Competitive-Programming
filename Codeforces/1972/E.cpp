#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, M = 1e6 + 5;
const ll MOD = 998244353;
ll n, k, a[N], b[N], pw[M], inv[M];
ll lb (ll x) {
    return x - (x & (x - 1));
}
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
    pw[0] = inv[0] = 1;
    for (ll i = 1; i <= M - 5; i ++)
        pw[i] = pw[i - 1] * i % MOD;
    inv[M - 5] = ksm (pw[M - 5], MOD - 2);
    for (ll i = M - 5; i >= 1; i --)
        inv[i - 1] = inv[i] * i % MOD;
    for (ll i = M - 5; i >= 1; i --)
        inv[i] = inv[i] * pw[i - 1] % MOD;
    // cout << inv[3] * 3ll % MOD << "\n";
}
void solve () {
    cin >> n >> k;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i ++) {
        if (1) {
        // } else {
            ll mul = 1;
            for (ll x = i + lb(i), d = 1; x <= n; x += lb(x), d ++) {
                mul *= (d + k - 1) % MOD;
                mul %= MOD;
                mul *= inv[d] % MOD;
                mul %= MOD;
                // cout << d + k - 1 << " " << d << ": " << mul << "\n";
                a[x] -= mul * a[i] % MOD;
                a[x] %= MOD;
                if (a[x] < 0)
                    a[x] += MOD;
            }
        }
    }
    for (int i = 1; i <= n; i ++)
        cout << a[i] << " ";
    cout << "\n";
}
int main () {
    init ();
    ios::sync_with_stdio (0);
    cin.tie (0);
    cout.tie (0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve ();
    }
    return 0;
}