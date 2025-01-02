#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
ll n;
ll cal (ll x) {
    ll l = 1, r = 3e9, ans = 3e9;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (mid * mid <= x) {
            ans = mid;
            l = mid + 1;
        } else
            r = mid - 1;
    }
    return x - ans;
}
void solve () {
    cin >> n;
    ll l = 1, r = 9e18, ans = 9e18;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (cal (mid) >= n) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    cout << ans << "\n";
}
int main () {
    ios::sync_with_stdio (0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve ();
    }
}