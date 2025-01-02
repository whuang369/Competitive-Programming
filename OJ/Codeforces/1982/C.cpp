#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
ll n, dp[N], l, r, a[N], d[N];
void solve () {
    cin >> n >> l >> r;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        dp[i] = 0;
        d[i] = d[i - 1] + a[i];
    }
    int cur = 0;
    for (int i = 1; i <= n; i ++) {
        while (d[i] - d[cur + 1] >= l)
            cur ++;
        dp[i] = max (dp[i - 1], dp[cur] + ((d[i] - d[cur] >= l && d[i] - d[cur] <= r) ? 1 : 0));
        // cout << i << ":" << dp[i] << " " << cur << "\n";
    }
    cout << dp[n] << "\n";
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