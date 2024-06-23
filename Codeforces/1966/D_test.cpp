#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, k;
void solve () {
    cin >> n >> k;
    vector <ll> v(n);
    for (int i = 0; i < n; i ++)
        cin >> v[i];
    set <ll> s;
    for (ll j = 1; j < (1 << n); j ++) {
        ll sum = 0;
        for (ll i = 0; i < n; i ++)
            if (j & (1 << i)) {
                sum += v[i];
                if (sum > k)
                    break ;
            }
        if (sum <= k)
            s.insert (sum);
    }
    for (ll x : s)
        cout << x << " ";
}
int main () {
    int T;
    // cin >> T;
    T = 1;
    while (T --) {
        solve ();
    }
}