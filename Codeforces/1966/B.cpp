#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n, m;
char ch[N][N];
void solve () {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j ++)
            ch[i][j] = s[j - 1];
    }
    if (ch[1][1] == ch[n][m]) {
        cout << "YES\n";
        return;
    }
    int ok1 = 0, ok2 = 0;
    for (int j = 1; j < m; j ++)
        if (ch[n][j] != ch[n][m]) {
            ok1 = 1;
            break ;
        }
    for (int i = 1; i < n; i ++)
        if (ch[i][m] != ch[n][m]) {
            ok2 = 1;
            break ;
        }
    if (ok1 && ok2) {
        cout << "YES\n";
        return ;
    }
    ok1 = 0, ok2 = 0;
    for (int j = 2; j <= m; j ++)
        if (ch[1][j] != ch[1][1]) {
            ok1 = 1;
            break ;
        }
    for (int i = 2; i <= n; i ++)
        if (ch[i][1] != ch[1][1]) {
            ok2 = 1;
            break ;
        }
    if (ok1 && ok2) {
        cout << "YES\n";
        return ;
    }
    cout << "NO\n";
}
int main () {
    int T;
    cin >> T;
    while (T --) {
        solve ();
    }
}