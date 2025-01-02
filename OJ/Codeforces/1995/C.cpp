#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
ll n, k, a[N], b[N];
void solve () {
    cin >> n >> k;
    map <ll, ll> mp;
    set <ll> st;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        
    ll ans = 0;
    for (int i = 0; i < v.size(); i ++) {
        ll num = min (mp[v[i]], (ll)k / v[i]);
        ans = max (ans, num * v[i]);
        for (int j = 1; j <= num; j ++) {
            ll sum = j * v[i];
            ll lft = k - sum;
            if (i != 0 && v[i] - v[i - 1] == 1) {
                ll num2 = min (mp[v[i - 1]], (ll)lft / v[i - 1]);
                ans = max (ans, sum + num2 * v[i - 1]);
            }
            if (i != v.size() - 1 && v[i + 1] - v[i] == 1) {
                ll num2 = min (mp[v[i + 1]], (ll)lft / v[i + 1]);
                ans = max (ans, sum + num2 * v[i + 1]);
            }
        }
    }
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