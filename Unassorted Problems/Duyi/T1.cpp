#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve () {
    map <int, ll> mp;
    int n;
    cin >> n;
    ll ans = 0;
    while (n --) {
        int x, y;
        cin >> x >> y;
        ans += mp[y - x];
        mp[y - x] ++;
    }
    cout << ans << "\n";
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        solve ();
    }
}