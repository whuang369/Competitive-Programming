#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e3 + 5;
int n, m, a[N], b[N];
int dp[N][N], s[N][N];
int ab (int x) {
    return max (x, -x);
}
int cal (int x, int y) {
    int dif = ab (a[x] - b[y]);
    if (dif <= 15)
        return 7;
    if (dif <= 23)
        return 6;
    if (dif <= 43)
        return 4;
    if (dif <= 102)
        return 2;
    return 0;
}
void solve () {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= m; i ++)
        cin >> b[i];
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++) {
            dp[i][j] = s[i - 1][j - 1] + cal (i, j);
            s[i][j] = max (s[i - 1][j], s[i][j - 1]);
            s[i][j] = max (dp[i][j], s[i][j]);
        }
    cout << s[n][m] << "\n";
}
int main () {
    ios::sync_with_stdio (0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        solve ();
    }
}