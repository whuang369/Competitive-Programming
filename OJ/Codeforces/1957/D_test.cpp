#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5, M = 32;
ll n, a[N], xsum[2][N], sum[2][N][M], dp[2][N][M][2], anss[N];
void solve () {
    cin >> n;
    memset (anss, 0, sizeof(anss));
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        xsum[0][i] = xsum[0][i - 1] ^ a[i];
    xsum[1][n + 1] = 0;
    for (int i = n; i >= 1; i --)
        xsum[1][i] = xsum[1][i + 1] ^ a[i];
    ll ans = 0;
    for (int i = 1; i <= n; i ++)
        for (int j = i; j <= n; j ++)
            for (int k = j; k <= n; k ++) {
                ll lhs = (xsum[0][j] ^ xsum[0][i - 1]) ^ (xsum[0][k] ^ xsum[0][j - 1]);
                ll rhs = xsum[0][k] ^ xsum[0][i - 1];
                if (lhs > rhs)
                    anss[j] ++;
            }
    for (int i = 1; i <= n; i ++)
        cout << i << ":" << anss[i] << "\n";
    cout << ans << "\n";
}
int main () {
    ios::sync_with_stdio (0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        solve ();
    }
    return 0;
}