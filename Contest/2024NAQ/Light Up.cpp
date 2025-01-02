#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
const int N = 35;
int n, a[N][N], ok = 1;
char c[N][N];
void lit (int x, int y, int dx, int dy) {
    a[x][y] = 1;
    x += dx;
    y += dy;
    if (x < 1 || x > n || y < 1 || y > n)
        return ;
    if (c[x][y] == '?')
        ok = 0;
    if (c[x][y] != '.')
        return ;
    lit (x, y, dx, dy);
}
void solve () {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j ++)
            c[i][j] = s[j - 1];
        for (int j = 1; j <= n; j ++)
            if (c[i][j] == '?') {
                a[i - 1][j] ++;
                a[i + 1][j] ++;
                a[i][j - 1] ++;
                a[i][j + 1] ++;
                if (c[i - 1][j] == '?' || c[i][j - 1] == '?')
                    ok = 0;
            }
    }
    if (!ok) {
        cout << "0\n";
        return ;
    }
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            if (c[i][j] != '.' && c[i][j] != 'X' && c[i][j] != '?') {
                int x = c[i][j] - '0';
                if (x != a[i][j]) {
                    ok = 0;
                    break ;
                }
            }
    if (!ok) {
        cout << "0\n";
        return ;
    }
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            a[i][j] = 0;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            if (c[i][j] == '?') {
                lit (i, j, 0, 1);
                lit (i, j, 0, -1);
                lit (i, j, 1, 0);
                lit (i, j, -1, 0);
            }
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            if (c[i][j] == '.' && a[i][j] != 1) {
                ok = 0;
                break ;
            }
    if (!ok) {
        cout << "0\n";
        return ;
    }
    cout << "1\n";
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