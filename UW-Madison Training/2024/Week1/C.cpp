#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2.5e3 + 5;
int n, vis[N], fa[N];
ll p[N][N];
int find (int x) {
    if (x == fa[x])
        return x;
    return fa[x] = find (fa[x]);
}
void merge (int x, int y) {
    int xx = find (x), yy = find (y);
    if (xx == yy)
        return ;
    fa[xx] = yy;
    return ;
}
bool cmp (pair <pair <int, int>, ll> a, pair <pair <int, int>, ll> b) {
    return a.second < b.second;
}
void solve () {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++)
            cin >> p[i][j];
        fa[i] = i;
    }
    vector <pair <pair <int, int>, ll> > v;
    for (int i = 1; i < n; i ++)
        for (int j = i + 1; j <= n; j ++)
            v.push_back (make_pair (make_pair (i, j), p[i][j]));
    sort (v.begin(), v.end(), cmp);
    ll sum = 0;
    int num = 0;
    for (int i = 0; i < v.size(); i ++) {
        if (find (v[i].first.first) != find (v[i].first.second)) {
            num ++;
            cout << v[i].first.first << " " << v[i].first.second << "\n";
        }
        merge (v[i].first.first, v[i].first.second);
        if (num == n - 1)
            break ;
    }
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