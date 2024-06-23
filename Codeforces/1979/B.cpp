#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll lb (ll x) {
    return x & (-x);
}
void solve () {
    ll x, y;
    cin >> x >> y;
    cout << lb(x ^ y) << "\n";
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