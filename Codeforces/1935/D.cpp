#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, c;
void solve () {
    cin >> n >> c;
    ll sum[2] = {0, 0};
    vector <ll> a(n);
    for (int i = 0; i < n; i ++) {
        ll x;
        cin >> x;
        a[i] = x;
        sum[x & 1] ++;
    }
    ll ans = (c + 1) * (c + 2) / 2;
    // cout << ans << "\n";
    for (ll x : a) {
        ll mx = c - x + c;
        ll nums = 0, len = mx + 1;
        if (x & 1) {
            if (len & 1)
                nums = (mx & 1 ? (len + 1) / 2 : (len - 1) / 2);
            else
                nums = len / 2;
        } else {
            if (len & 1)
                nums = (mx & 1 ? (len - 1) / 2 : (len + 1) / 2);
            else
                nums = len / 2;
        }
        nums -= sum[x & 1];
        // cout << x << ":" << nums << "\n";
        ans -= nums;
    }
    ans -= sum[0] * (sum[0] + 1) / 2;
    ans -= sum[1] * (sum[1] + 1) / 2;
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
}