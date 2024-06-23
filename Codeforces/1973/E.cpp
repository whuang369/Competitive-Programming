#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2 * 1e5 + 5;
int n, a[N], vis[N];
vector <int> v, v2[N];
void dfs (int x) {
    v.push_back (x + a[x]);
    x = a[x];
    if (vis[x])
        return ;
    vis[x] = 1;
    dfs (x);
}
void solve () {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], vis[i] = 0;
    for (int i = 1; i <= 2 * n; i ++)
        v2[i].clear();
    int mnl = 2 * n, mnr = 2 * n;
    for (int i = 1; i <= n; i ++)
        if (!vis[i]) {
            vis[i] = 1;
            v.clear ();
            dfs (i);
            sort (v.begin(), v.end());
            if (v.size() == 1)
                continue;
            int siz = v.size();
            v2[v[0] + 1].push_back(v[siz - 1]);
            mnl = min (mnl, v[1]);
            mnr = min (mnr, v[siz - 2]);
        }
    if (mnr == 2 * n)
        mnr = 1;
    ll ans = 0;
    for (int l = 1; l <= mnl; l ++) {
        for (int x : v2[l])
            mnr = max (mnr, x);
        mnr = max (mnr, l);
        ans += (ll)(2 * n - mnr + 1);
        // cout << l << " " << mnr << "\n";
    }
    cout << ans << "\n";
}
int main () {
    ios::sync_with_stdio (false);
    cin.tie (0);
    cout.tie (0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve ();
    }
}