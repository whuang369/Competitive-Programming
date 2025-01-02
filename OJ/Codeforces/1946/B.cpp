#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD = 1e9 + 7, N = 2e5 + 5;
ll n, k, a[N], d[N];
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
void solve () {
    cin >> n >> k;
    ll mn = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        d[i] = a[i] + d[i - 1];
    }
    ll mx = 0;
    for (int i = 1; i <= n; i ++) {
        mx = max (mx, d[i] - mn);
        mn = min (mn, d[i]);
    }
    mx %= MOD;
    ll ans = d[n] + mx * (ksm (2, k) - 1) % MOD;
    ans %= MOD;
    if (ans < 0)
        ans += MOD;
    cout << ans << "\n";
}
int main () {
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