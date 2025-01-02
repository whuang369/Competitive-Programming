#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
int n, a[N];
void solve () {
    cin >> n;
    int mx = 0, mxx = 0;
    ll sum = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        mx = max (mx, a[i]);
        if (a[i] < mx) {
            sum += mx - a[i];
            mxx = max (mxx, mx - a[i]);
        }
    }
    sum += mxx;
    cout << sum << "\n";
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