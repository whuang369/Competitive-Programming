#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e3 + 5;
const ll INF = 1e18;
int n, a[N], vis[N], tot[N];
ll dp[N][N];
void solve () {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        tot[i] = 0;
    for (int i = 0; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            dp[i][j] = INF;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        vis[i] = 0;
        tot[a[i]] ++;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i ++) {
        if (!tot[i])
            continue ;
        cnt ++;
        a[cnt] = i;
    }
    for (int i = 1; i <= cnt; i ++)
        for (int j = 1; j <= i; j ++) {
            dp[i][j] = dp[i - 1][j];
            if (dp[i - 1][j - 1] + tot[a[i]] <= i - j)
                dp[i][j] = min (dp[i][j], dp[i - 1][j - 1] + tot[a[i]]);
        }
    int ans = cnt;
    for (int i = 1; i <= cnt; i ++)
        if (dp[cnt][i] <= cnt - i)
            ans = cnt - i;
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
}