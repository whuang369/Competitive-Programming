#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 3e5 + 5, MOD = 998244353;
ll n, q, l[N], r[N], pw[N], inv[N];
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
    return ;
}
ll C (ll x, ll y) {
    if (x < y)
        return 0;
    return pw[x] * inv[y] % MOD * inv[x - y] % MOD;
}
void solve () {
    cin >> n >> q;
    map <int, int> mp;
    for (int i = 1; i <= q; i ++) {
        cin >> l[i];
        mp[l[i]] = 1;
    }
    for (int i = 1; i <= q; i ++) {
        cin >> r[i];
        mp[r[i]] = 1;
    }
    ll ans = 1, now = 2;
    for (int i = n; i >= 1; i --)
        if (!mp[i]) {
            ans *= now;
            ans %= MOD;
            now ++;
        } else
            now += 2;
    cout << ans << "\n";
}
int main () {
    init ();
    ios::sync_with_stdio (0);
    cin.tie (0);
    cout.tie (0);
    int T = 1;
    // cin >> T;
    while (T --) {
        solve ();
    }
}