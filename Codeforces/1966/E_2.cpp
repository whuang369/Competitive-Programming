#include <bits/stdc++.h>
using namespace std;
string s;
int n;
void solve () {
    cin >> n >> s;
    int mn, mx;
    mn = mx = 0;
    int cur = 0, dir = 1;
    for (int i = 1; i < n; i ++) {
        if (s[i] == s[i - 1])
            dir = -dir;
        else {
            cur += dir;
            mn = min (mn, cur);
            mx = max (mx, cur);
        }
    }
    cout << mx - mn + 1 << "\n";
}
int T;
int main () {
    ios::sync_with_stdio (false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T --) {
        solve ();
    }
}