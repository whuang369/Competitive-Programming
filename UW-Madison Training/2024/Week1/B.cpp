#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
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
bool cmp (pair <pair <int, int>, double> a, pair <pair <int, int>, double> b) {
    return a.second < b.second;
}
void solve () {
    cin >> n;
    int sum = 1;
    double cost = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> p[i].first >> p[i].second;
        fa[i] = i;
    }
    vector <pair <pair <int, int>, double> > v;
    for (int i = 1; i < n; i ++)
        for (int j = i + 1; j <= n; j ++)
            v.push_back (make_pair (make_pair (i, j), cal (p[i], p[j])));
    sort (v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i ++) {
        if (find (v[i].first.first) != find (v[i].first.second)) {
            sum ++;
            cost += v[i].second;
        }
        merge (v[i].first.first, v[i].first.second);
        if (sum == n)
            break ;
    }
    cout << fixed << setprecision (14) << cost << "\n";
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