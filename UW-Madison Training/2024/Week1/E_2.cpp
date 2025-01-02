#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
const ll INF = 0x3f3f3f3f;
int n, m, q, s, vis[N], cnt[N], neg[N];
vector <pair <int, ll> > g[N];
ll dis[N];
void dfs (int x) {
    neg[x] = 1;
    for (auto p : g[x]) {
        int y = p.first;
        if (!neg[y])
            dfs (y);
    }
    return ;
}
void spfa () {
    queue <int> q;
    for (int i = 0; i < n; i ++)
        dis[i] = INF, vis[i] = 0, cnt[i] = 0, neg[i] = 0;
    q.push (s);
    dis[s] = 0;
    while (!q.empty()) {
        int x = q.front();
        ll cost = dis[x];
        q.pop();
        vis[x] = 0;
        if (cnt[x] >= 2 * n)
            continue;
        for (auto p : g[x]) {
            int y = p.first;
            ll d = cost + p.second;
            if (dis[y] > d) {
                cnt[y] = cnt[x] + 1;
                if (cnt[y] >= n) {
                    neg[y] = 1;
                }
                if (!vis[y]) {
                    dis[y] = d;
                    q.push (y);
                    vis[y] = 1;
                }
            }
        }
    }
}
void solve () {
    cin >> n >> m >> q >> s;
    if (!n && !m && !q && !s)
        exit (0);
    for (int i = 0; i < n; i ++)
        g[i].clear();
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        ll dis;
        cin >> dis;
        g[u].push_back (make_pair (v, dis));
    }
    spfa ();
    while (q --) {
        int x; cin >> x;
        if (neg[x])
            cout << "-Infinity\n";
        else if (dis[x] == INF)
            cout << "Impossible\n";
        else
            cout << dis[x] << "\n";
    }
}
int main () {
    ios::sync_with_stdio (0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T) {
        solve ();
    }
}