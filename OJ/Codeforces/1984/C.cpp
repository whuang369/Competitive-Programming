#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
const ll MOD = 998244353;
ll n;
ll ab (ll x) {
    return max (x, -x);
}
void solve () {
    cin >> n;
    vector <pair <ll, ll> > now;
    now.push_back (make_pair (0, 1));
    for (int i = 1; i <= n; i ++) {
        ll x;
        cin >> x;
        vector <pair <ll, ll> > v;
        for (auto p : now) {
            v.push_back (make_pair (p.first + x, p.second));
            v.push_back (make_pair (ab(p.first + x), p.second));
        }
        sort (v.begin(), v.end());
        ll mn = v[0].first, mnsum = 0;
        ll mx = v[v.size() - 1].first, mxsum = 0;
        for (auto p : v) {
            if (mn == p.first) {
                mnsum += p.second;
                mnsum %= MOD;
            }
            if (mx == p.first) {
                mxsum += p.second;
                mxsum %= MOD;
            }
        }
        now.clear();
        if (mn == mx) {
            now.push_back (make_pair (mn, mnsum));
        } else {
            now.push_back (make_pair (mn, mnsum));
            now.push_back (make_pair (mx, mxsum));
        }
    }
    cout << now[now.size() - 1].second << "\n";
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