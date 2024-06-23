#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 64;
ll n, m, a[N], b[N];
void solve() {
    cin >> n >> m;
    for (ll i = 0; i < N; i ++) {
        if ((1ll << i) & n)
            a[i] = 1;
        else
            a[i] = 0;
        if ((1ll << i) & m)
            b[i] = 1;
        else
            b[i] = 0;
    }
    if ((n ^ m) <= n) {
        cout << "1\n";
        cout << n << " " << m << "\n";
    } else {
        ll xr = n ^ m, mx = 1;
        for (ll i = N - 1; i >= 0; i --)
            if (a[i] == 1) {
                xr ^= (1ll << i);
                mx = (1ll << i);
                break ;
            }
        if ((n ^ xr) > n) {
            cout << "-1\n";
            return ;
        }
        cout << "2\n";
        cout << n << " " << (n ^ xr) << " " << m << "\n";
    }
    return ;
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