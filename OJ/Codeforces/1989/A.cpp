#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll ab (ll x) {
    return max (x, -x);
}
void solve () {
    ll x, y;
    cin >> x >> y;
    if (y < -1) {
        cout << "NO\n";
    } else
        cout << "YES\n";
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