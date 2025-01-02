#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N], vis[N], fa[N];
int find (int x) {
    return (fa[x] == x ? x : fa[x] = find (fa[x]));
}
void merge (int x, int y) {
    int xx = find (x), yy = find (y);
    if (xx == yy)
        return;
    fa[xx] = yy;
    return ;
}
void solve () {
    cin >> n;
    map <int, int> mp;
    for (int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        mp[x] = i;
        vis[i] = 0;
    }
    int ok = 1;
    for (int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        if (!mp[x])
            ok = 0;
        a[i] = mp[x];
        if (vis[mp[x]])
            ok = 0;
        vis[mp[x]] = 1;
    }
    if (!ok) {
        cout << "NO\n";
        return ;
    }
    for (int i = 1; i <= n; i ++)
        fa[i] = i;
    for (int i = 1; i <= n; i ++)
        merge (i, a[i]);
    int cnt = 0;
    for (int i = 1; i <= n; i ++)
        if (find(i) == i)
            cnt ++;
    if (cnt % 2 != n % 2) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve();
    }
}