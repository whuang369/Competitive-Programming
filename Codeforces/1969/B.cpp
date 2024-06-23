#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
void solve () {
    cin >> s;
    int n = s.size ();
    s = "0" + s;
    ll ans = 0, cnt = 0;
    for (int i = 1; i <= n; i ++) {
        cnt += s[i] == '0';
    }
    int pos = 1;
    for (int i = 1; i <= n; i ++)
        if (s[i] == '0') {
            if (i != pos)
                ans += i - pos + 1;
            pos ++;
        }
    cout << ans << "\n";
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
    return 0;
}