#include <bits/stdc++.h>
using namespace std;
const int N = 405;
int n, m, a[N][N];
void solve () {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            cin >> a[i][j];
    int mn = 1e9;
    for (int i = 1; i <= m; i ++)
        for (int j = i + 1; j <= m; j ++) {
            int sum = 0;
            for (int k = 1; k <= n; k ++)
                sum += min (a[k][i], a[k][j]);
            mn = min (mn, sum);
        }
    cout << mn << "\n";
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