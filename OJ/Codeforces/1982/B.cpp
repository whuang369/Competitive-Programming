#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve () {
    ll x, y, k;
    cin >> x >> y >> k;
    while (x != 1) {
        ll lft = y - (x % y);
        if (lft >= k) {
            x += k;
            while (x % y == 0)
                x /= y;
            cout << x << "\n";
            return ;
        }
        x += lft;
        while (x % y == 0)
            x /= y;
        k -= lft;
    }
    k %= (y - 1);
    x += k;
    cout << x << "\n";
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