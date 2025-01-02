#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e3 + 5;
int nxt[N][N];
void solve () {
    int n;
    string s;
    cin >> s;
    n = s.size();
    for (int len = 1; len * 2 - 1 <= n - 1; len ++)
        for (int l = 0; l + len <= n - 1; l ++) {
            if (s[l] != s[l + len] && s[l] != '?' && s[l + len] != '?')
                nxt[l][len] = 0;
            else
                nxt[l][len] = 1;
        }
    // cout << s[3] << s[6] << "\n";
    // cout << nxt[3][3] << "\n";
    for (int len = 1; len * 2 - 1 <= n - 1; len ++)
        for (int l = 0; l + len <= n - 1; l ++)
            nxt[l][len] += (l == 0 ? 0 : nxt[l - 1][len]);
    int mx = 0;
    // cout << nxt[1 + 3 - 1][3] << " " << nxt[1 - 1][3] << "\n";
    for (int len = 1; len * 2 - 1 <= n - 1; len ++) {
        int ok = 0;
        for (int l = 0; l + len * 2 - 1 <= n - 1; l ++) {
            int sum1 = nxt[l + len - 1][len] - (l == 0 ? 0 : nxt[l - 1][len]);
            if (sum1 == len) {
                ok = 1;
                break ;
            }
        }
        if (ok)
            mx = len;
    }
    cout << mx * 2 << "\n";
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