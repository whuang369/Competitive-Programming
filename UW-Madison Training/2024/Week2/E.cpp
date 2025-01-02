#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 5;
const ll INF = 0x3f3f3f3f;
int n, m, s, t, lim, vis[N];
ll d[N], dd[N];
vector <pair <int, ll> > g[N];
bool check (ll D) {
    if (dd[s] < D || dd[t] < D)
        return false;
    priority_queue <pair <ll, int> > q;
    for (int i = 0; i < n; i ++)
        d[i] = INF, vis[i] = 0;
    q.push (make_pair (0, s));
    d[s] = 0;
    while (!q.empty()) {
        int x = q.top().second;
        q.pop();
        if (vis[x])
            continue ;
        vis[x] = 1;
        for (auto p : g[x]) {
            int y = p.first;
            ll diss = d[x] + p.second;
            if (dd[y] >= D && !vis[y] && d[y] > diss) {
                d[y] = diss;
                q.push (make_pair (-d[y], y));
            }
        }
    }
    if (d[t] > lim)
        return false;
    return true;
}
void solve () {
    cin >> n >> m >> lim;
    for (int i = 0; i < n; i ++)
        d[i] = INF;
    for (int i = 1; i <= m; i ++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        g[u].push_back(make_pair (v, w));
        g[v].push_back(make_pair (u, w));
    }
    cin >> s >> t;
    priority_queue <pair <ll, int> > q;
    int T;
    cin >> T;
    while (T --) {
        int x;
        cin >> x;
        q.push (make_pair (0, x));
        d[x] = 0;
    }
    ll mx = 0;
    while (!q.empty()) {
        int x = q.top().second;
        ll dis = d[x];
        q.pop();
        if (vis[x])
            continue ;
        vis[x] = 1;
        for (auto p : g[x]) {
            int y = p.first;
            ll diss = dis + p.second;
            if (!vis[y] && d[y] > diss) {
                d[y] = diss;
                q.push (make_pair (-d[y], y));
            }
        }
    }
    for (int i = 0; i < n; i ++) {
        mx = max (d[i], mx);
        dd[i] = d[i];
        vis[i] = 0;
    }
    ll l = 0, r = INF, ans;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (check (mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << "\n";
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