#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
int n, a[N];
void solve () {
    cin >> n;
    int lft = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        // if (a[i])
        //     lft ++;
    }
    ll ans = 0;
    // while (lft) {
    //     lft = 0;
    //     ans ++;
    //     for (int i = 1; i <= n; i ++) {
    //         if (a[i] != 0 && (i == n || a[i] > a[i + 1])) {
    //             a[i] --;
    //         }
    //         if (a[i])
    //             lft ++;
    //     }
    //     cout << ans << ": ";
    //     for (int i = 1; i <= n; i ++)
    //         cout << a[i] << " ";
    //     cout << "\n";
    // }
    ans = a[n];
    for (int i = n - 1; i >= 1; i --) {
        if (a[i] > ans)
            ans = a[i];
        else
            ans ++;
    }
    cout << ans << "\n";
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