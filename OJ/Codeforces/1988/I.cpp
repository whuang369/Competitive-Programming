#include <bits/stdc++.h>
#define db double
#define ll long long
using namespace std;
const int N = 305;
const ll MOD = 1e9 + 7;
int n;
ll dp[7][2];
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
ll div (ll x) {
    return ksm (x, MOD - 2);
}
void solve () {
    cin >> n;
    for (int i = 1; i <= 6; i ++)
        dp[i][1] = div (6);
    ll sum = 1;
    for (int i = 2; i <= n; i ++) {
        int cur = i & 1;
        int lst = 1 - cur;
        for (int j = 1; j <= 6; j ++)
            dp[j][cur] = 0;
        sum = 0;
        for (int j = 1; j <= 6; j ++) {
            for (int k = 1; k <= 6; k ++) {
                if (k > j)
                    continue;
                dp[j][cur] += dp[k][lst] * div(6) % MOD;
            }
            sum += dp[j][cur];
            sum %= MOD;
        }
    }
    cout << sum << "\n";
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