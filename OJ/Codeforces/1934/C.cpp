#include <bits/stdc++.h>
#define F first
#define S second
#define mk make_pair
#define ll long long
using namespace std;
ll n, m;
ll query (ll x, ll y) {
    cout << "? " << x << " " << y << "\n";
    cout.flush();
    ll ret = 0;
    cin >> ret;
    return ret;
}
void solve() {
    cin >> n >> m;
    ll d1 = query (1, 1);
    ll xx1 = 1, yy1 = d1 + 1;
    if (yy1 > m) {
        xx1 += yy1 - m;
        yy1 = m;
    }
    ll xx2 = d1 + 1, yy2 = 1;
    if (xx2 > n) {
        yy2 += xx2 - n;
        xx2 = n;
    }
    ll d2 = query (xx1, yy1);
    ll d3 = query (xx2, yy2);
    ll x1 = xx1 + d2 / 2, y1 = yy1 - d2 / 2;
    ll x2 = xx2 - d3 / 2, y2 = yy2 + d3 / 2;
    int ans = query (x1, y1);
    if (!ans) {
        cout << "! " << x1 << " " << y1 << "\n";
    } else
        cout << "! " << x2 << " " << y2 << "\n";
    cout.flush();
}
int main () {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve ();
    }
}