#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 15, M = 2e5 + 5;
vector <pair <int, int> > v[N][N];
int n, m, fa[M];
int find (int x) {
    return fa[x] == x ? x : fa[x] = find (fa[x]);
}
void merge (int x, int y) {
    int xx = find (x), yy = find (y);
    if (xx == yy)
        return ;
    fa[xx] = yy;
    return ;
}
void solve () {
    cin >> n >> m;
    for (int i = 1; i <= 10; i ++)
        for (int j = 0; j < i; j ++)
            v[i][j].clear ();
    for (int i = 1; i <= m; i ++) {
        int a, d, k;
        cin >> a >> d >> k;
        v[d][a % d].push_back (make_pair (a, a + d * k));
    }
    for (int i = 1; i <= n; i ++)
        fa[i] = i;
    for (int i = 1; i <= 10; i ++)
        for (int j = 0; j < i; j ++) {
            sort (v[i][j].begin(), v[i][j].end());
            for (int k = 0; k < v[i][j].size(); k ++) {
                int l = v[i][j][k].first, r = v[i][j][k].second;
                while (k != v[i][j].size() - 1 && v[i][j][k + 1].first <= r) {
                    k ++;
                    r = max (r, v[i][j][k].second);
                }
                int now = l;
                while (now < r) {
                    if (now + i <= r)
                        merge (now, now + i);
                    now += i;
                }
            }
        }
    int sum = 0;
    for (int i = 1; i <= n; i ++)
        if (find (i) == i) {
            sum ++;
            // cout << i << "\n";
        }
    cout << sum << "\n";
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