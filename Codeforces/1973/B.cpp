#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int xorsum[N][20];
void solve () {
    int n;
    cin >> n;
    vector <int> a (n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        for (int j = 0; j < 20; j ++)
            xorsum[i][j] = (i == 0 ? 0 : xorsum[i - 1][j]) + !!(a[i] & (1 << j));
    }
    int l = 1, r = n, ans = n;
    while (l <= r) {
        int k = (l + r) >> 1;
        int ok = 1;
        for (int i = 0; i + k - 1 < n - 1; i ++) {
            int comp[2] = {0, 0};
            for (int j = 0; j < 20; j ++) {
                if (xorsum[i + k - 1][j] - (i == 0 ? 0 : xorsum[i - 1][j]) != 0)
                    comp[0] |= (1 << j);
                if (xorsum[i + k][j] - xorsum[i][j] != 0)
                    comp[1] |= (1 << j);
            }
            if (comp[1] != comp[0]) {
                ok = 0;
                break ;
            }
        }
        if (ok) {
            ans = k;
            r = k - 1;
        } else {
            l = k + 1;
        }
    }
    cout << ans << "\n";
}
int main () {
    ios::sync_with_stdio (false);
    cin.tie (0);
    cout.tie (0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve ();
    }
}