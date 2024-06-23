#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
int n, a[N], vis[N], cnt;
vector <int> v[N], v2[N];
void dfs (int x) {
    v[cnt].push_back (x + a[x]);
    x = a[x];
    if (vis[x])
        return ;
    vis[x] = cnt;
    dfs (x);
}
void solve () {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], vis[i] = 0, v[i].clear ();
    for (int i = 1; i <= 2 * n; i ++)
        v2[i].clear();
    int mnl = 2 * n, mnr = 2 * n;
    cnt = 0;
    for (int i = 1; i <= n; i ++)
        if (!vis[i]) {
            cnt ++;
            v[cnt].clear ();
            vis[i] = cnt;
            dfs (i);
            sort (v[cnt].begin(), v[cnt].end());
            // for (int x : v[cnt])
            //     cout << x << " ";
            // cout << "\n";
        }
    int sum = 0;
    for (int l = 1; l <= 2 * n; l ++) {
        int sum2 = 0;
        for (int r = l; r <= 2 * n; r ++) {
            int ok = 1;
            for (int k = 1; k <= cnt; k ++) {
                int siz = v[k].size ();
                if (siz == 1)
                    continue ;
                int mn = v[k][0], mn2 = v[k][1], mx2 = v[k][siz - 2], mx = v[k][siz - 1];
                if (l > mn2 || r < mx2) {
                    ok = 0;
                    break;
                }
                if (l > mn && r < mx) {
                    ok = 0;
                    break ;
                }
            }
            sum += ok;
            sum2 += ok;
        }
        // cout << l << ":" << sum2 << "\n";
    }
    cout << sum << "\n";
}
int main () {
    ios::sync_with_stdio (false);
    cin.tie (0);
    cout.tie (0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve ();
    }
}