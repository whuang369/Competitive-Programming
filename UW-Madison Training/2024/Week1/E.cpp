#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
const ll INF = 0x3f3f3f3f;
int n, m, q, s, neg[N];
vector <pair <pair <int, int>, ll> > g;
ll dis[N];
void bf () {
    for (int i = 0; i < n; i ++)
        dis[i] = INF, neg[i] = 0;
    dis[s] = 0;
    int tims = 2 * n;
    while (tims --) {
        for (auto p : g) {
            int x = p.first.first, y = p.first.second;
            ll z = p.second;
            if (dis[x] != INF && dis[y] > dis[x] + z) {
                if (tims <= n)
                    dis[y] = -INF;
                else
                    dis[y] = dis[x] + z;
            }
        }
    }
}
void solve () {
    cin >> n >> m >> q >> s;
    if (!n && !m && !q && !s)
        exit (0);
    g.clear();
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        ll diss;
        cin >> diss;
        g.push_back(make_pair(make_pair(u, v), diss));
    }
    bf ();
    while (q --) {
        int x; cin >> x;
        if (dis[x] == -INF)
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