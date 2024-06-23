#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
int n, d[N], vis[N], rnd[N], cnt;
vector <int> v[N];
void dfs (int x) {
    for (int y : v[x]) {
        if (d[y])
            continue;
        d[y] = d[x] + 1;
        dfs (y);
    }
}
pair <int, int> find_dia () {
    for (int i = 1; i <= n; i ++)
        d[i] = 0;
    d[1] = 1;
    dfs (1);
    int d1 = 0;
    for (int i = 1; i <= n; i ++)
        if (d[i] > d[d1])
            d1 = i;
    for (int i = 1; i <= n; i ++)
        d[i] = 0;
    d[d1] = 1;
    dfs (d1);
    int d2 = 0;
    for (int i = 1; i <= n; i ++)
        if (d[i] > d[d2])
            d2 = i;
    return make_pair (d1, d2);
}
bool rec_road (int x, int tar) {
    rnd[++ cnt] = x;
    vis[x] = 1;
    if (x == tar)
        return true;
    for (int y : v[x])
        if (!vis[y]) {
            if (rec_road(y, tar))
                return true;
        }
    cnt --;
    return false;
}
void solve () {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        v[i].clear();
    for (int i = 1; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    pair <int, int> p = find_dia();
    int dis = d[p.second];
    for (int i = 1; i <= n; i ++)
        vis[i] = 0;
    cnt = -1;
    rec_road(p.first, p.second);
    // for (int i = 0; i <= cnt; i ++)
    //     cout << rnd[i] << " ";
    // cout << ":road points\n";
    // cout << p.first << " " << p.second << ":distance\n";
    if (dis & 1) {
        int mid = dis / 2;
        cout << (dis + 1) / 2 << "\n";
        cout << rnd[mid] << " 0\n";
        for (int i = 1; mid - i >= 0; i ++)
            cout << rnd[mid] << " " << i << "\n";
    } else {
        int mid1 = dis / 2 - 1, mid2 = dis / 2;
        int ans_cnt = 0;
        for (int i = 1; mid1 - i >= 0 || mid1 + i < dis; i += 2)
            ans_cnt ++;
        for (int i = 1; mid2 - i >= 0 || mid2 + i < dis; i += 2)
            ans_cnt ++;
        cout << ans_cnt << "\n";
        for (int i = 1; mid1 - i >= 0 || mid1 + i < dis; i += 2)
            cout << rnd[mid1] << " " << i << "\n";
        for (int i = 1; mid2 - i >= 0 || mid2 + i < dis; i += 2)
            cout << rnd[mid2] << " " << i << "\n";
    }
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