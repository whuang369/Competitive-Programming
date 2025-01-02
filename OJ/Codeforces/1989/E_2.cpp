#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
const ll MOD = 998244353;
ll n, k, sum[15], dp[N][15];
void solve () {
    cin >> n >> k;
    dp[0][0] = sum[0] = 1;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= min ((ll)i, k); j ++) {
            dp[i][j] = (sum[j - 1] + (j == k ? sum[j] : 0)) % MOD;
            if (i > 2 && i != n)
                dp[i][j] -= (dp[i - 2][j - 1] + (j == k ? dp[i - 2][j] : 0));
            dp[i][j] = (dp[i][j] + MOD) % MOD;
        }
        for (int j = 1; j <= k; j ++)
            sum[j] = (sum[j] + dp[i][j]) % MOD;
    }
    cout << dp[n][k] << "\n";
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