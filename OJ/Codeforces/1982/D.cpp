#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e2 + 5;
ll n, m, k, sumq[N][N], a[N][N];
ll gcd (ll x, ll y) {
    return (y == 0 ? x : gcd (y, x % y));
}
void solve () {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++) {
            cin >> a[i][j];
            sumq[i][j] = 0;
        }
    ll now = -1, diff = 0;
    for (int i = 1; i <= n; i ++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j ++) {
            if (s[j - 1] == '1') {
                sumq[i][j] = 1;
                diff += a[i][j];
            } else {
                sumq[i][j] = -1;
                diff -= a[i][j];
            }
            sumq[i][j] += sumq[i - 1][j] + sumq[i][j - 1] - sumq[i - 1][j - 1];
        }
    }
    diff = max (diff, -diff);
    for (int i = k; i <= n; i ++)
        for (int j = k; j <= m; j ++) {
            ll reg = sumq[i][j] - sumq[i - k][j] - sumq[i][j - k] + sumq[i - k][j - k];
            reg = max (reg, -reg);
            if (reg == 0)
                continue;
            if (now == -1)
                now = reg;
            else
                now = gcd (now, reg);
        }
    // cout << diff << " " << now << "\n";
    if ((now == -1 && diff == 0) || (now != -1 && diff % now == 0))
        cout << "YES\n";
    else
        cout << "NO\n";
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