#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
ll n, a[N];
void solve () {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    ll mx = -1;
    for (int i = 2; i <= n; i ++)
        mx = max (mx, min (a[i - 1], a[i]));
    for (int i = 3; i <= n; i ++) {
        vector <ll> v(3);
        v[0] = a[i - 2];
        v[1] = a[i - 1];
        v[2] = a[i];
        sort (v.begin (), v.end());
        mx = max (mx, v[1]);
    }
    cout << mx << "\n";
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
    return 0;
}