#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e5 + 5, M = 11;
ll n, k, a[N], dp[N][M], sum[N], ans, tot;
void solve () {
    cin >> n >> k;
    for (int j = 0; j <= k; j ++)
        dp[0][j] = 0;
    ans = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        ans += a[i];
        sum[i] = sum[i - 1] + a[i];
        for (int j = 0; j <= k; j ++)
            dp[i][j] = 0;
    }
    tot = ans;
    for (int i = 1; i <= n; i ++) {
        // cout << i << ": ";
        for (int j = 1; j <= min ((int)k, i - 1); j ++) {
            vector <ll> mnp (j + 1);
            ll mn = a[i];
            mnp[0] = mn;
            for (int l = 1, pos = i - 1; l <= j; l ++, pos --) {
                mn = min (mn, a[pos]);
                mnp[l] = mn;
            }
            for (int l = 0; l <= j; l ++) {
                dp[i][j] = max (dp[i][j], dp[i - l - 1][j - l] + sum[i] - sum[i - l - 1] - mnp[l] * (l + 1));
            }
            ans = min (ans, tot - dp[i][j]);
            // cout << dp[i][j] << "|" << j << " ";
        }
    }
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