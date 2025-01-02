#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD = 1e9 + 7;
ll n, k;
bool isok (ll x) {
    ll sum = 0;
    while (x) {
        sum += x % 2;
        x >>= 1;
    }
    return sum <= k;
}
void solve () {
    cin >> n >> k;
    ll now = 0, ans = 0, ttt = 0;
    for (ll i = 0; i < n; i ++) {
        if (!isok (i)) {
            ans += now * (now + 1) / 2 % MOD;
            if (now != 0) {
                ttt ++;
                cout << now << "\n";
            }
            now = 0;
        } else {
            now ++;
        }
    }
    ans += now * (now + 1) / 2 % MOD;
    if (now != 0) {
        ttt ++;
        cout << now << "\n";
    }
    cout << ans << ":" << ttt << "\n";
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