#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 5, M = 2e6;
ll n, m, phi[N];
ll gcd (ll x, ll y) {
    return y == 0 ? x : gcd (y, x % y);
}
void solve () {
    cin >> n >> m;
    ll ans = 0;
    for (ll i = 1; i * i <= n; i ++) {
        for (ll j = 1; j * j <= m; j ++) {
            if (gcd (i, j) == 1)
                ans += (ll)(min ((ll)(n / i), (ll)(m / j)) / (i + j));
        }
    }
    cout << ans << "\n";
}
int T;
int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T --) {
        solve ();
    }
    return 0;
}