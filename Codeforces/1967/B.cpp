#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve () {
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    for (ll i = 1; i <= m; i ++)
        ans += ((n / i) + 1) / i;
    cout << ans - 1 << "\n";
}
int main () {
    int T;
    cin >> T;
    while (T --) {
        solve ();
    }
}