#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 5;
pair <double, double> p[N];
int m, n, vis[N], fa[N];
double cal (pair <double, double> a, pair <double, double> b) {
    double x = a.first - b.first;
    double y = a.second - b.second;
    return sqrt (x * x + y * y);
}
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
void dfs (int x, double D) {
    vis[x] = 1;
    for (int i = 1; i <= n; i ++)
        if (!vis[i] && cal (p[i], p[x]) <= D) {
            merge (i, x);
            dfs (i, D);
        }
    return ;
}
bool check (double D) {
    for (int i = 1; i <= n; i ++)
        fa[i] = i, vis[i] = 0;
    for (int i = 1; i <= n; i ++)
        if (!vis[i])
            dfs (i, D);
    set <int> s;
    for (int i = 1; i <= n; i ++)
        s.insert (find (i));
    int sum = s.size();
    if (sum <= m)
        return true;
    return false;
}
void solve () {
    cin >> m >> n;
    for (int i = 1; i <= n; i ++)
        cin >> p[i].first >> p[i].second;
    vector <double> v;
    v.push_back (0);
    for (int i = 1; i < n; i ++)
        for (int j = i + 1; j <= n; j ++)
            v.push_back (cal (p[i], p[j]));
    sort (v.begin(), v.end());
    int l = 0, r = v.size() - 1;
    double ans = v[v.size() - 1];
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check (v[mid])) {
            ans = v[mid];
            r = mid - 1;
        } else
            l = mid + 1;
    }
    cout << fixed << setprecision (2) << ans << "\n";
}
int main () {
    ios::sync_with_stdio (0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve ();
    }
}