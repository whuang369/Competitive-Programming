#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 5;
int n, a[N], fa[N];
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
int cnt2 = 0, vis[N];
void dfs (int x) {
    vis[x] = 1;
    cnt2 ++;
    if (vis[a[x]])
        return ;
    dfs (a[x]);
}
set <vector <int> > se;
bool check (string s) {
    for (int i = 1; i <= n; i ++)
        a[i] = s[i - 1] - '0', vis[i] = 0;
    cnt2 = 0;
    int ok = 1, ct = 0, cir = 0;
    vector <int> v;
    for (int i = 1; i <= n; i ++)
        if (!vis[i]) {
            cnt2 = 0;
            cir ++;
            dfs (i);
        }
    if (cir & 1)
        return false;
    return true;
}
void solve () {
    cin >> n;
    map <string, int> mp;
    string s[N];
    for (int i = 1; i <= n; i ++)
        a[i] = i;
    int cnt = 0;
    do {
        cnt ++;
        string cur = "";
        for (int i = 1; i <= n; i ++)
            cur += char (a[i] + '0');
        mp[cur] = cnt;
        fa[cnt] = cnt;
        s[cnt] = cur;
    } while (next_permutation (a + 1, a + n + 1));
    for (int i = 1; i <= cnt; i ++) {
        for (int l = 1; l <= n; l ++)
            for (int r = l + 1; r <= n; r ++) {
                for (int ls = 1; ls + (r - l) <= n; ls ++) {
                    int rs = ls + r - l;
                    if (l == ls)
                        continue;
                    string t = s[i];
                    swap (t[l - 1], t[r - 1]);
                    swap (t[ls - 1], t[rs - 1]);
                    int num = mp[t];
                    merge (i, num);
                }
            }
    }
    int sum = 0, sum2 = 0;
    for (int i = 1; i <= cnt; i ++) {
        if (find (i) != find (1)) {
            sum ++;
            // check (s[i]);
        }
        if (!check(s[i]) && find (i) == find (1)) {
            sum2 ++;
            // cout << s[i] << "\n";
        }
    }
    for (auto v : se) {
        for (int x : v)
            cout << x << " ";
        cout << "\n";
    }
    // cout << "--------------------\n";
    // for (int i = 1; i <= cnt; i ++) {
    //     if (find (i) != find (1)) {
    //         cout << s[i] << "\n";
    //         // sum ++;
    //     }
    //     if (!check(s[i]) && find (i) == find (1)) {
    //         // sum2 ++;
    //     }
    // }
    cout << sum << " " << sum2 << "\n";
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        solve();
    }
}