#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll n, m;
void solve () {
    cin >> n >> m;
    ll l = max (0ll, n - m), r = n + m;
    ll ans = 0;
    for (int i = 31; i >= 0; i --)
        if ((1ll << i) & n) {
            ans |= (1ll << i);
            continue ;
        } else {
            ll l2 = (((n >> i) - 1) << i) + (1 << i) - 1;
            ll r2 = ((n >> i) + 1) << i;
            if (l2 >= l || r2 <= r) {
                ans |= (1ll << i);
            }
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