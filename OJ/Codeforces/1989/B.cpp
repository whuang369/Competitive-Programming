#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 105;
string s, t;
int nxt[N][26], lst[26];
void solve () {
    cin >> s >> t;
    int n = s.size(), m = t.size();
    for (int j = 0; j < 26; j ++)
        nxt[n - 1][j] = lst[j] = -1;
    lst[s[n - 1] - 'a'] = n - 1;
    for (int i = n - 2; i >= 0; i --) {
        for (int j = 0; j < 26; j ++)
            nxt[i][j] = nxt[i + 1][j];
        nxt[i][s[i + 1] - 'a'] = i + 1;
        lst[s[i] - 'a'] = i;
    }
    int mx = 0;
    for (int len = 1; len <= m; len ++) {
        for (int l = 0; l + len - 1 < m; l ++) {
            int r = l + len - 1;
            int now = -1;
            now = lst[t[l] - 'a'];
            if (now == -1)
                continue;
            int ok = 1;
            for (int i = l + 1; i <= r; i ++) {
                now = nxt[now][t[i] - 'a'];
                if (now == -1) {
                    ok = 0;
                    break ;
                }
            }
            if (!ok)
                continue ;
            mx = len;
            break ;
        }
    }
    cout << n + m - mx << "\n";
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