#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
ll ab (ll x) {
    if (x < 0)
        return -x;
    return x;
}
ll n, a[N], b[N];
void solve () {
    cin >> n;
    for (int i = 0; i < n; i ++)
        cin >> a[i];
    for (int i = 0; i < n + 1; i ++)
        cin >> b[i];
    ll ans = 0, ok = 0;
    for (int i = 0; i < n; i ++) {
        ll mn = min (a[i], b[i]), mx = max (a[i], b[i]);
        ans += mx - mn;
        if (mn <= b[n] && b[n] <= mx) {
            ok = 1;
        }
    }
    if (ok == 1) {
        ans ++;
    } else {
        ll ft = 1e9;
        ft = min (ab(a[0] - b[n]), ab(b[0] - b[n]));
        for (int i = 0; i < n; i ++) {
            ft = min (ft, min (ab(a[i] - b[n]), ab(b[i] - b[n])));
        }
        ans += ft;
        ans ++;
    }
    cout << ans << "\n";
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