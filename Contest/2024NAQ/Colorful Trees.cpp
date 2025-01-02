#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
ll n, b[N], col[N], ans[N], vis[N];
vector <int> v[N];
map <pair <int, int>, int> imp;
void dfs (int x, map <int, int>& mp) {
    vis[x] = 1;
    mp[col[x]] = 1;
    for (int y : v[x]) {
        if (vis[y])
            continue ;
        int num = imp[make_pair (x, y)];
        map <int, int> nxt;
        dfs (y, nxt);
        for (auto p : nxt) {
            int c = p.first;
            ll ai = p.second;
            ans[num] += ai * (b[c] - ai);
        }
        if (mp.size() < nxt.size())
            swap (mp, nxt);
        for (auto p : nxt)
            mp[p.first] += p.second;
    }
}
void solve () {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> col[i];
        b[col[i]] ++;
    }
    for (int i = 1; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        imp[make_pair (x, y)] = imp[make_pair (y, x)] = i;
        v[x].push_back (y);
        v[y].push_back (x);
    }
    map <int, int> ls;
    dfs (1, ls);
    for (int i = 1; i < n; i ++)
        cout << ans[i] << "\n";
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