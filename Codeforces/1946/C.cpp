#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
int n, k, s[N], cur, now;
vector <int> v[N];
void dfs (int x, int fa) {
    s[x] = 1;
    for (int y : v[x]) {
        if (y == fa)
            continue;
        dfs (y, x);
        s[x] += s[y];
    }
    if (s[x] >= now)
        s[x] = 0, cur ++;
}
void solve () {
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        v[i].clear ();
    for (int i = 1; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back (y);
        v[y].push_back (x);
    }
    int l = 0, r = n / (k + 1), ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        now = mid;
        cur = 0;
        dfs (1, 0);
        if (cur >= k + 1) {
            ans = mid;
            l = mid + 1;
        } else
            r = mid - 1;
    }
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