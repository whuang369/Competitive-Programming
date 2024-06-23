#include <bits/stdc++.h>
using namespace std;
int n;
string s;
void solve () {
    cin >> n >> s;
    int cnt = 0;
    for (int i = 0; i < n; i ++)
        cnt += (s[i] == '1' ? 1 : 0);
    if (cnt % 2) {
        cout << "NO\n";
        return ;
    }
    if (cnt == 2) {
        int ok = 1;
        for (int i = 0; i < n - 1; i ++)
            if (s[i] == '1' && s[i + 1] == '1') {
                ok = 0;
                break ;
            }
        if (!ok)
            cout << "NO\n";
        else
            cout << "YES\n";
    } else
        cout << "YES\n";
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