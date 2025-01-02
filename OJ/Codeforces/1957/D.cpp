#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5, M = 32;
ll n, a[N], xsum[2][N], sum[2][N][M][2], dp[2][N][M][2];
void solve () {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        xsum[0][i] = xsum[0][i - 1] ^ a[i];
    xsum[1][n + 1] = 0;
    for (int i = n; i >= 1; i --)
        xsum[1][i] = xsum[1][i + 1] ^ a[i];
    for (int i = 1; i <= n; i ++)
        for (int j = 0; j < M; j ++) {
            ll val = ((a[i] & (1ll << j)) ? 1 : 0);
            for (int k = 0; k < 2; k ++)
                sum[0][i][j][k] = sum[0][i - 1][j][k ^ val] + (val == k);
        }
    for (int j = 0; j < M; j ++)
        for (int k = 0; k < 2; k ++)
            sum[1][n + 1][j][k] = 0;
    for (int i = n; i >= 1; i --)
        for (int j = 0; j < M; j ++) {
            ll val = ((a[i] & (1ll << j)) ? 1 : 0);
            for (int k = 0; k < 2; k ++)
                sum[1][i][j][k] = sum[1][i + 1][j][k ^ val] + (val == k);
        }
    ll ans = 0;
    for (int i = 1; i <= n; i ++) {
        int mxbit = 0;
        for (int j = 0; j < M; j ++)
            if (a[i] & (1ll << j))
                mxbit = j;
        ll l0 = sum[0][i - 1][mxbit][0];
        ll l1 = sum[0][i - 1][mxbit][1];
        ll r0 = sum[1][i + 1][mxbit][0];
        ll r1 = sum[1][i + 1][mxbit][1];
        r0 ++;
        l0 ++;
        // printf ("%d:\nl1:%d l0:%d r1:%d r0:%d\n", i, l1, l0, r1, r0);
        // cout << i << ":" << l1 * r0 + l0 * r1 << "\n";
        ans += l1 * r0 + l0 * r1;
    }
    cout << ans << "\n";
}
int main () {
    ios::sync_with_stdio (0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve ();
    }
    return 0;
}