#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e5 + 5, MOD = 1e9 + 7;
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
ll cal (ll p, ll q) {
    return p * ksm (q, MOD - 2) % MOD;
}
ll inv_4;
ll n, p[N], a[N], dp[2][2], p_2[10], pos_2[10][10], ls[2][2], invp[N];
void solve () {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++) {
        cin >> p[i];
        invp[i] = (10000 - p[i]) * inv_4 % MOD;
        p[i] = p[i] * inv_4 % MOD;
    }
    ll ans = 0;
    for (int p1 = 0; p1 < 10; p1 ++)
        for (int p2 = 0; p2 < 10; p2 ++) {
            dp[0][1] = dp[1][0] = dp[1][1] = 0;
            dp[0][0] = 1;
            ll val = (1ll << p1) * (1ll << p2);
            for (int i = 1; i <= n; i ++) {
                int cur1 = (a[i] & (1 << p1)) ? 1 : 0;
                int cur2 = (a[i] & (1 << p2)) ? 1 : 0;
                ls[0][0] = ls[0][1] = ls[1][0] = ls[1][1] = 0;
                for (int j = 0; j < 2; j ++)
                    for (int k = 0; k < 2; k ++) {
                        ls[j ^ cur1][k ^ cur2] += dp[j][k] * p[i] % MOD;
                        ls[j ^ cur1][k ^ cur2] %= MOD;
                        ls[j][k] += dp[j][k] * invp[i] % MOD;
                        ls[j][k] %= MOD;
                    }
                for (int j = 0; j < 2; j ++)
                    for (int k = 0; k < 2; k ++)
                        dp[j][k] = ls[j][k];
            }
            ans += dp[1][1] * val % MOD;
            ans %= MOD;
        }
    cout << ans << "\n";
}
int main () {
    inv_4 = ksm (10000, MOD - 2);
    ios::sync_with_stdio (0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve ();
    }
}