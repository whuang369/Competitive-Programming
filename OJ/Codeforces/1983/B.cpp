#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 5;
int n, m, a[N][N], b[N][N], d[N][N];
void solve () {
    cin >> n >> m;
    int ok = 1;
    for (int i = 1; i <= n; i ++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j ++) {
            if (s[j - 1] == '1')
                a[i][j] = 1;
            else if (s[j - 1] == '2')
                a[i][j] = 2;
            else
                a[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i ++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j ++) {
            int x = 0;
            if (s[j - 1] == '1')
                x = 1;
            else if (s[j - 1] == '2')
                x = 2;
            a[i][j] = x - a[i][j];
            if (a[i][j] < 0)
                a[i][j] += 3;
            d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + a[i][j];
            d[i][j] += 3;
            d[i][j] %= 3;
        }
    }
    for (int i = 1; i <= n; i ++)
        if (d[i][m] != d[i - 1][m])
            ok = 0;
    for (int i = 1; i <= m; i ++)
        if (d[n][i] != d[n][i - 1])
            ok = 0;
    if (ok)
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
        solve();
    }
}