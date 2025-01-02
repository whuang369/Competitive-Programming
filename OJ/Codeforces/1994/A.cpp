#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int a[N][N], n, m;
void solve () {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            cin >> a[i][j];
    if (n == 1 && m == 1) {
        cout << "-1\n";
        return ;
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++)
            cout << a[i][j] % (n * m) + 1 << " ";
        cout << "\n";
    }
    return ;
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