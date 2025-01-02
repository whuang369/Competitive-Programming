#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
int n, m;
ll a[N], b[N], c[N], dp[N];
pair <int, int> p[N];
void solve () {
    cin >> n >> m;
    ll mx = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        mx = max (mx, a[i]);
    }
    for (int i = 1; i <= n; i ++) {
        cin >> b[i];
        p[i].first = a[i];
        p[i].second = b[i];
    }
    sort (p + 1, p + n + 1);
    for (int i = 1; i <= m; i ++)
        cin >> c[i];
    int now = 0, mn = N;
    for (int i = 1; i <= mx; i ++) {
        while (now < n && p[now + 1].first <= i) {
            now ++;
            mn = min (mn, p[now].first - p[now].second);
        }
        if (now == 0) {
            dp[i] = 0;
            continue;
        }
        int d = mn;
        dp[i] = dp[i - d] + 2;
    }
    ll ans = 0;
    for (int i = 1; i <= m; i ++) {
        ll x = c[i], sum = 0;
        ll d = mn;
        if (x > p[n].first) {
            ll dis = x - p[n].first;
            ll tims = dis / d;
            if (tims * d < dis)
                tims ++;
            sum += tims * 2;
            x -= tims * d;
        }
        sum += dp[x];
        ans += sum;
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