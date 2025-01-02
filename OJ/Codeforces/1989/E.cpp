#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
const ll MOD = 998244353;
ll n, k, dp[N][15], sum[15];
ll dis_s (ll x) {
    return (x * (x + 1) / 2) % MOD;
}
ll dis (ll x) {
    if (x & 1)
        return ((x + 1) / 2) * ((x + 1) / 2) % MOD;
    else
        return (x / 2) * (x / 2 + 1) % MOD;
}
void solve () {
    cin >> n >> k;
    for (int i = 0; i <= n; i ++) {
        for (int j = 2; j <= k; j ++)
            dp[i][j] = 0;
        dp[i][0] = 0;
        dp[i][1] = dis_s (i);
    }
    sum[0] = 1;
    dp[0][0] = 1;
    for (ll i = 1; i <= n; i ++) {
        for (ll j = 2; j <= min (i, k); j ++) {
            dp[i][j] = sum[j - 1] * (k - j + 1) % MOD;
            dp[i][j] += sum[j] * (j - 1);
            dp[i][j] %= MOD;
        }
        for (ll j = 1; j <= min (i, k); j ++) {
            sum[j] += dp[i][j];
            sum[j] %= MOD;
        }
    }
    for (int i = 1; i <= n; i ++, cout << "\n")
        for (int j = 1; j <= k; j ++)
            cout << dp[i][j] << " ";
    ll ans = 0;
    for (ll i = k; i <= n; i ++) {
        ll sum = dp[i - 1][k - 1] * dis_s(n - i + 1) % MOD;
        sum += dp[i - 1][k] * k % MOD * dis_s(n - i + 1) % MOD;
        sum %= MOD;
        ans += sum;
        ans %= MOD;
    }
    cout << ans << "\n";
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        solve ();
    }
}