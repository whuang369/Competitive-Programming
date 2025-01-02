#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int n, a[N];
ll sum[N], ans, num[N], ans_num[N];
vector <int> v[N];
void dfs (int x, int fa) {
    int col = a[x];
    num[col] ++;
    cout << x << " " << ans_num[col] << "\n";
    ans += ans_num[col];
    int cur = num[col], mns = ans_num[col];
    ans_num[col] = 0;
    for (int y : v[x]) {
        if (y == fa)
            continue ;
        dfs (y, x);
    }
    ans += num[col] - cur;
    ans_num[col] ++;
    ans_num[col] -= num[col] - cur;
    ans_num[col] += mns;
    num[col] = cur;
    return ;
}
void solve () {
    ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        sum[i] = 0;
        v[i].clear();
        num[i] = 0;
    }
    for (int i = 1; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back (y);
        v[y].push_back (x);
    }
    dfs (1, -1);
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