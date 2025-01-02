#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 45;
int n, k, a[N], c[N];
int ab (int x) {
    return max (x, -x);
}
void solve () {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    int mn = 2 * n;
    // do {
        int mx = -1;
        for (int i = 1; i <= n; i ++)
            for (int j = i + 1; j <= n; j ++)
                mx = max (mx, ab(i - j) + ab(a[i] - a[j]));
        mn = min (mn, mx);
        // if (n == mx) {
        //     for (int i = 1; i <= n; i ++)
        //         cout << a[i] << " ";
        //     cout << "\n";
        // }
    // } while (next_permutation (a + 1, a + n + 1));
    cout << mn << "\n";
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