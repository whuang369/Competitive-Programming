#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e3 + 5, M = 1e6;
const ll MOD = 998244353;
ll n, q, fnd, num, vis[N][N], lst[N];
ll cnt, pri[M + 5], isp[M + 5];
void init (ll M) {
    cnt = 0;
    for (int i = 2; i <= M; i ++)
        isp[i] = 0;
    for (ll i = 2; i <= M; i ++) {
        if (!isp[i])
            pri[++ cnt] = i;
        for (int j = 1; j <= cnt; j ++) {
            ll y = pri[j] * i;
            if (y > M)
                break;
            isp[y] = 1;
            if (pri[j] >= i)
                break ;
        }
    }
}
ll mx_len (ll x) {
    if (x & 1)
        return x * (x + 1) / 2;
    else
        return x * (x + 1) / 2 - (x / 2 - 1);
}
void dfs (int x) {
    // cout << x << ":" << lst[x] << "\n";
    while (lst[x] <= fnd) {
        while (lst[x] <= fnd && (vis[x][lst[x]] || vis[lst[x]][x]))
            lst[x] ++;
        if (lst[x] > fnd)
            break ;
        vis[x][lst[x]] = 1;
        dfs (lst[x]);
        if (num >= n)
            return ;
    }
    if (num >= n)
        return ;
    num ++;
    cout << pri[x] << " ";
}
void solve () {
    cin >> n;
    ll l = 1, r = 2000;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (mx_len(mid) >= n - 1) {
            fnd = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    // cout << fnd << "\n";
    for (int i = 1; i <= fnd; i ++) {
        for (int j = 1; j <= fnd; j ++)
            vis[i][j] = 0;
        lst[i] = 1;
    }
    if (!(fnd & 1))
        for (int i = 2; i <= fnd; i += 2)
            vis[i][i + 1] = 1;
    num = 0;
    dfs (1);
    cout << "\n";
}
int main () {
    init (M);
    ios::sync_with_stdio (false);
    cin.tie (0);
    cout.tie (0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve ();
    }
}