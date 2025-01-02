#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
void solve () {
    cin >> n;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    ll L = -1, R = -1;
    ll val = -1, ok = 1;
    for (int i = 1; i <= n; i ++) {
        if (L == -1 && a[i] != i)
            L = i;
        if (a[i] != i) {
            R = i;
            if (val == -1)
                val = a[i] + i;
            if (val != -1 && val != a[i] + i)
                ok = 0;
        }
    }
    if (L == -1) {
        cout << 2ll * n * (2ll * n + 1ll) / 2ll << "\n";
        return ;
    }
    ll ans = ok;
    for (ll i = 1; i <= n + L; i ++) {
        ll r = max (i + 1, R + 1);
        ans += 2 * n - r + 1;
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
    return 0;
}