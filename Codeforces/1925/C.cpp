#include <bits/stdc++.h>
using namespace std;

#ifdef local
#include<local/debug>
#else
#define dbg(...)
#endif


using i64 = long long;

int n, k, m, app[30];
string s;

void solve() {
    cin >> n >> k >> m >> s;
    set <char> se;
    int sum = 0, tot = 0;
    string ans = "";
    memset (app, 0, sizeof (app));
    for (int i = 0; i < m; i ++) {
        if (!app[s[i] - 'a'])
            sum ++;
        app[s[i] - 'a'] = 1;
        // cout << sum << " ";
        if (sum == k) {
            ans += s[i];
            // cout << i << " ";
            for (int i = 0; i < 26; i ++)
                app[i] = 0;
            sum = 0;
            tot ++;
        }
    }
    // cout << "\n";
    if (tot < n) {
        cout << "NO\n";
        int num = 0;
        for (int i = 0; i < 26; i ++)
            if (!app[i]) {
                num = i;
                break;
            }
        for (int i = 1; i <= n - tot; i ++)
            ans += char (num + 'a');
        cout << ans << "\n";
    }
    else
        cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}