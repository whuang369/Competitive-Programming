#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 405;
int n, m;
ll kk, a[N][N], s[N][N], val[N][N][N], dp[N][N];
void solve () {
    cin >> n >> m >> kk;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> a[i][j];
            s[i][j] = s[i][j - 1] + a[i][j];
        }
        for (int j = m + 1; j <= 2 * m; j ++) {
            a[i][j] = a[i][j - m];
            s[i][j] = s[i][j - 1] + a[i][j];
        }
    }
    dp[0][1] = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            dp[i][j] = -1;
            for (int k = 1; k <= (i == 1 ? 1 : j); k ++) {
                for (int l = 0; l <= m - 1; l ++) {
                    ll cur = dp[i - 1][k] + s[i][l + j] - s[i][l + k - 1] + l * kk;
                    if (dp[i][j] == -1)
                        dp[i][j] = cur;
                    else
                        dp[i][j] = min (dp[i][j], cur);
                }
            }
        }
    }
    cout << dp[n][m] << "\n";
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
}