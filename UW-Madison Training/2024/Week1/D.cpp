#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
const ll INF = 0x3f3f3f3f;
int n, m, fr[N], bk[N], vis[N];
vector <pair <int, ll> > g[N];
ll dis[N];
vector <int> ans;
void dij () {
    priority_queue <pair <ll, int> > q;
    for (int i = 0; i < n; i ++)
        dis[i] = INF, fr[i] = -1, bk[i] = -1, vis[i] = 0;
    q.push (make_pair (0, 1));
    dis[1] = 0;
    while (!q.empty()) {
        int x = q.top().second;
        ll cost = -q.top().first;
        q.pop();
        if (vis[x])
            continue ;
        vis[x] = 1;
        for (auto p : g[x]) {
            int y = p.first;
            ll d = cost + p.second;
            if (!vis[y] && dis[y] > d) {
                dis[y] = d;
                fr[y] = x;
                q.push (make_pair (-d, y));
            }
        }
    }
    int now = 0;
    while (now != 1) {
        bk[fr[now]] = now;
        now = fr[now];
    }
}
bool dfs (int x) {
    vis[x] = 1;
    if (x == 1) {
        ans.push_back (1);
        return true;
    }
    for (auto p : g[x]) {
        int y = p.first;
        if (!vis[y] && fr[x] != y)
            if (dfs (y)) {
                ans.push_back (x);
                return true;
            }
    }
    return false;
}
void solve () {
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        ll dis;
        cin >> dis;
        g[u].push_back (make_pair (v, dis));
        g[v].push_back (make_pair (u, dis));
    }
    dij ();
    ans.clear();
    for (int i = 0; i < n; i ++)
        vis[i] = 0;
    if (dfs (0)) {
        cout << ans.size() << " ";
        for (int i = ans.size() - 1; i >= 0; i --)
            cout << ans[i] << " ";
        cout << "\n";
    } else
        cout << "impossible\n";
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