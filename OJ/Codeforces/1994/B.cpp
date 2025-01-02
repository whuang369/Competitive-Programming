#include <bits/stdc++.h>
using namespace std;
void solve () {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int exi = -1;
    for (int i = 0; i < n; i ++) {
        if (s[i] == '1') {
            exi = 1;
            break ;
        }
        if (s[i] != t[i]) {
            if (exi == -1) {
                cout << "NO\n";
                return ;
            }
        }
    }
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