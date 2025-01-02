#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd (ll a, ll b) {
    if (b != 0)
        return gcd (b, a % b);
    else
        return a;
}
void solve () {
    for (ll c = 1; c <= 100; c ++) {
        int ans = 0;
        cout << c << ":\n";
        for (ll a = 1; a <= c; a ++)
            for (ll b = 1; b <= c; b ++)
                if (gcd (a, b) == 1) {
                    if (c % (a + b) == 0) {
                        ans ++;
                        cout << a << " " << b << "\n";
                    }
                }
        cout << ans << "\n";
    }
    // ll n, m, l, r;
    // cin >> n >> m >> l >> r;
    // ll ans = 0;
    // for (ll a = max (l, 2ll); a <= n; a ++)
    //     for (ll b = max (r, 2ll); b <= m; b ++) {
    //         ll rhs = a + b;
    //         ll lhs = b * gcd (a, b);
    //         if (lhs % rhs == 0)
    //             ans ++;
    //     }
    // cout << ans << "\n";
}
int main () {
    int T;
    // cin >> T;
    T = 1;
    while (T --) {
        solve ();
    }
}