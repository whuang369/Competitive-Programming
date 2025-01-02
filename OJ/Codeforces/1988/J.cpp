#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int mn = 1e9, a[N][N];
void solve () {
    int n = 10;
    int T;
    cin >> T;
    if (T == 1)
        cout << 106 << "\n";
    else {
        int now = 100;
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                if ((i + j) % 2 == 0) {
                    a[i][j] = now;
                    now --;
                }
        now = 1;
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                if ((i + j) % 2 == 1) {
                    a[i][j] = now;
                    now ++;
                }
        int mx = -1;
        for (int i = 1; i <= n; i ++, cout << "\n")
            for (int j = 1; j <= n; j ++) {
                cout << a[i][j] << " ";
                mx = max (mx, a[i][j] + a[i + 1][j]);
                mx = max (mx, a[i][j] + a[i][j + 1]);
            }
        // cout << mx << "\n";
    }
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