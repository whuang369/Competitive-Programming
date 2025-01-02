#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 55;
int n, a[N], l, r;
void solve () {
    cin >> n >> l >> r;
    n --;
    int mn = 100, mx = -1;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        mn = min (mn, a[i]);
        mx = max (mx, a[i]);
    }
    if (l != mn && r != mx) {
        cout << "-1\n";
        return ;
    }
    if (l != mn) {
        cout << l << "\n";
        return ;
    }
    if (r != mx) {
        cout << r << "\n";
        return ;
    }
    for (int i = l; i <= r; i ++)
        cout << i << "\n";
    return ;
}
int main () {
    ios::sync_with_stdio (0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        solve ();
    }
}