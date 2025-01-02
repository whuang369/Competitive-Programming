#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
int n, d, sum, cl[N], vis[N], p[N];
vector <int> v[N];
void col (int x, int step) {
    if (step == d) {
        if (!cl[x])
            sum ++;
        cl[x] = 1;
        return ;
    }
    for (int y : v[x]) {
        if (vis[y] != vis[x]) {
            vis[y] = vis[x];
            col (y, step + 1);
        }
    }
}
void solve () {
    cin >> n;
    for (int i = 1; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back (y);
        v[y].push_back (x);
        vis[i] = cl[i] = 0;
        p[i] = i;
    }
    vis[n] = cl[n] = 0;
    p[n] = n;
    for (d = 1; d <= n; d ++) {
        for (int i = 1; i <= n; i ++)
            p[i] = i;
        int ans = n;
        do {
            for (int i = 1; i <= n; i ++)
                cl[i] = vis[i] = 0;
            int mns = 0;
            sum = 0;
            for (int i = 1; i <= n; i ++) {
                vis[p[i]] = p[i];
                col (p[i], 0);
                mns ++;
                if (sum == n)
                    break ;
            }
            if (sum != n)
                continue ;
            ans = min (ans, mns);
            if (mns == 4) {
                for (int i = 1; i <= 4; i ++)
                    cout << p[i] << " ";
                cout << "\n";
            }
        } while (next_permutation(p + 1, p + n + 1));
        cout << d << ":" << ans << "\n";
    }
}
int main () {
    ios::sync_with_stdio (0);
    cin.tie (0);
    cout.tie (0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve ();
    }
}