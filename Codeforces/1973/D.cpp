#include <bits/stdc++.h>
using namespace std;
int n, k, mx;
int req (int l, int x) {
    cout << "? " << l << " " << x << "\n";
    cout.flush ();
    int temp; cin >> temp;
    return temp;
}
void termi () {
    int x;
    cin >> x;
    if (x != 1)
        exit (0);
}
void solve () {
    cin >> n >> k;
    mx = n;
    if (n == 1) {
        if (k == 1) {
            cout << "! 1\n";
        } else
            cout << "! -1\n";
        cout.flush();
        return ;
    }
    while (mx) {
        int x = req (1, n * mx);
        if (x != n + 1) {
            break ;
        }
        mx --;
    }
    int ans = -1;
    for (int m = mx; m <= mx * (int)(n / k); m += mx) {
        int r = 0, cnt = 0, ok = 1;
        while (cnt < k) {
            r = req (r + 1, m);
            cnt ++;
            if (r >= n)
                break ;
        }
        if (cnt == k && r == n) {
            ans = m;
        }
    }
    cout << "! " << ans << "\n";
    cout.flush();
}
int main () {
    // ios::sync_with_stdio (false);
    // cin.tie (0);
    // cout.tie (0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve ();
        termi ();
    }
}