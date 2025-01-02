#include <bits/stdc++.h>
#define db double
#define ll long long
using namespace std;
const int N = 1e6 + 5;
const ll MOD = 1e9 + 7;
ll n;
ll ksm (ll x, ll y) {
    ll ret = 1, now = x;
    while (y) {
        if (y & 1) {
            ret *= now;
            ret %= MOD;
        }
        now *= now;
        now %= MOD;
        y >>= 1;
    }
    return ret;
}
ll div (ll x) {
    return ksm (x, MOD - 2);
}
void solve () {
    cin >> n;
    ll ans = 1;
    ans *= div (2);
    ans %= MOD;
    ans *= div (n + 3);
    ans %= MOD;
    ans *= div (n + 4);
    ans %= MOD;
    cout << ans << "\n";
}
int main () {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        solve ();
    }
}