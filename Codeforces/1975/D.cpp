#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int n, ans, vist, a[N], dep[N], fa[N], mxdep[N];
vector <int> v[N], rt;
void dfs (int x) {
    mxdep[x] = dep[x];
    for (int y : v[x]) {
        if (!dep[y]) {
            dep[y] = dep[x] + 1;
            fa[y] = x;
            dfs (y);
            mxdep[x] = max (mxdep[x], mxdep[y]);
        }
    }
}
void mktr (int x) {
    for (int i = 1; i <= n; i ++)
        dep[i] = 0, fa[i] = 0;
    dep[x] = 1;
    fa[x] = -1;
    dfs (x);
}
void tort (int x) {
    rt.push_back (x);
    if (fa[x] != -1)
        tort (fa[x]);
}
bool cmp (int x, int y) {
    return mxdep[x] < mxdep[y];
}
void solve () {
    cin >> n;
    int a, b; cin >> a >> b;
    for (int i = 1; i <= n; i ++)
        v[i].clear ();
    for (int i = 1; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back (y);
        v[y].push_back (x);
    }
    mktr (a);
    int len = dep[b]; ans = len / 2;
    fa[a] = -1;
    rt.clear();
    tort (b);
    int midpoint = rt[ans];
    mktr (midpoint);
    vist = 0;
    ans += (n - 1) * 2;
    ans -= mxdep[midpoint] - 1;
    cout << ans << "\n";
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve ();
    }
    return 0;
}