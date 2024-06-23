#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, a[6][6], b[6][6];
void operate () {
    int c[6][6];
    memset (c, 0, sizeof (c));
    for (int i = 1; i <= 5; i ++)
        for (int j = 1; j <= 5; j ++)
            for (int k = 1; k <= 5; k ++) {
                c[i][j] += a[i][k] * b[k][j];
            }
    for (int i = 1; i <= 5; i ++)
        for (int j = 1; j <= 5; j ++)
            a[i][j] = c[i][j];
    return ;
}
void solve () {
    n = 5;
    a[0][0] = 0;
    a[0][1] = 0;
    a[0][2] = 0;
    a[0][3] = 0;
    a[0][4] = 0;
    a[0][5] = 0;
    a[1][0] = 0;
    a[1][1] = 0;
    a[1][2] = -1;
    a[1][3] = 1;
    a[1][4] = -1;
    a[1][5] = 1;
    a[2][0] = 0;
    a[2][1] = 1;
    a[2][2] = 1;
    a[2][3] = -1;
    a[2][4] = 1;
    a[2][5] = -1;
    a[3][0] = 0;
    a[3][1] = -1;
    a[3][2] = 0;
    a[3][3] = 1;
    a[3][4] = -1;
    a[3][5] = 1;
    a[4][0] = 0;
    a[4][1] = 1;
    a[4][2] = 0;
    a[4][3] = 0;
    a[4][4] = 1;
    a[4][5] = -1;
    a[5][0] = 0;
    a[5][1] = -1;
    a[5][2] = 0;
    a[5][3] = 0;
    a[5][4] = 0;
    a[5][5] = 1;
    for (int i = 1; i <= 5; i ++)
        for (int j = 1; j <= 5; j ++)
            b[i][j] = a[i][j];
    int n = 0;
    cin >> n;
    while (n != -1) {
        for (int i = 1; i <= 5; i ++)
            for (int j = 1; j <= 5; j ++)
                a[i][j] = b[i][j];
        for (int i = 0; i < n; i ++)
            operate ();
        for (int i = 1; i <= 5; i ++, cout << "\n")
            for (int j = 1; j <= 5; j ++)
                cout << a[i][j] << " ";
        cin >> n;
    }
}
int main () {
    ios::sync_with_stdio (0);
    cin.tie (0);
    cout.tie (0);
    int T = 1;
    // cin >> T;
    while (T --) {
        solve ();
    }
    return 0;
}