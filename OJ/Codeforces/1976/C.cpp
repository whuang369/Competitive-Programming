#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
ll n, m, a[N], b[N];
ll solve2 (int nx, int mx, int len) {
    ll sum = 0;
    int an = nx, bn = mx;
    for (int i = 1; i <= len; i ++)
        if (a[i] < b[i]) {
            if (bn != 0) {
                bn --;
                sum += b[i];
            } else {
                an --;
                sum += a[i];
            }
        } else {
            if (an != 0) {
                an --;
                sum += a[i];
            } else {
                bn --;
                sum += b[i];
            }
        }
    return sum;
}
void solve () {
    cin >> n >> m;
    for (int i = 1; i <= n + m + 1; i ++)
        cin >> a[i];
    for (int i = 1; i <= n + m + 1; i ++)
        cin >> b[i];
    ll am = solve2 (n + 1, m, n + m + 1), bm = solve2 (n, m + 1, n + m + 1), abm = solve2 (n, m, n + m);
    vector <ll> ans(n + m + 2);
    int an = n, bn = m;
    for (int i = 1; i <= n + m + 1; i ++) {
        int ga = 0;
        if (i == n + m + 1) {
            ans[i] = abm;
            break ;
        }
        if (an == 0)
            ga = -1;
        else if (bn == 0)
            ga = 1;
        else if (a[i] > b[i])
            ga = 1;
        else
            ga = -1;
        if (ga == 1)
            ans[i] = am - a[i], an --;
        else
            ans[i] = bm - b[i], bn --;
    }
    for (int i = 1; i <= n + m + 1; i ++)
        cout << ans[i] << " ";
    cout << "\n";
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