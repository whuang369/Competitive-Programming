#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, cur, d[N], rt[N];
vector <int> v[N];
map <string, int> mp;
void dfs (int x) {
    if (d[x])
        return ;
    if (v[x].size() == 0) {
        d[x] = 1;
        return ;
    }
    int mx = -1;
    for (int y : v[x]) {
        dfs (y);
        mx = max (mx, d[y]);
    }
    d[x] = mx + 1;
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        string s, t;
        cin >> s >> t;
        if (!mp[s])
            mp[s] = ++ cur;
        if (!mp[t])
            mp[t] = ++ cur;
    }
    for (int i = 1; i <= m; i ++) {
        string s, t;
        cin >> s >> t;
        if (!mp[s])
            mp[s] = ++ cur;
        if (!mp[t])
            mp[t] = ++ cur;
        int x = mp[s], y = mp[t];
        v[x].push_back (y);
        rt[y] = -1;
    }
    int ans1 = cur, ans2 = 0;
    for (int i = 1; i <= cur; i ++)
        if (!d[i]) {
            dfs (i);
        }
    for (int i = 1; i <= cur; i ++)
        if (rt[i] != -1 && v[i].size() != 0)
            ans2 += d[i];
    cout << ans2 << " " << ans1 << "\n";
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