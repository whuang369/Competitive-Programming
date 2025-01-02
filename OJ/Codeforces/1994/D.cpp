#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
int n, a[N], fa[N];
int find (int x) {
    return (x == fa[x] ? x : fa[x] = find (fa[x]));
}
void merge (int x, int y) {
    int xx = find (x), yy = find (y);
    if (xx == yy)
        return ;
    fa[xx] = yy;
}
void solve () {
    cin >> n;
    int ok = 1;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        fa[i] = i;
    }
    vector <pair <int, int> > ans;
    for (int now = n - 1; now >= 1; now --) {
        vector <int> v[now];
        for (int i = 1; i <= n; i ++)
            v[a[i] % now].push_back (i);
        int okk = 0;
        for (int i = 0; i < now && okk == 0; i ++)
            for (int x : v[i]) {
                if (find (x) != find (v[i][0])) {
                    merge (x, v[i][0]);
                    ans.push_back (make_pair (x, v[i][0]));
                    okk = 1;
                    break ;
                }
            }
        if (!okk) {
            ok = 0;
            break ;
        }
    }
    if (!ok) {
        return ;
    }
    cout << "YES\n";
    for (int i = 0; i < ans.size(); i ++)
        cout << ans[ans.size() - i - 1].first << " " << ans[ans.size() - i - 1].second << "\n";
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
}