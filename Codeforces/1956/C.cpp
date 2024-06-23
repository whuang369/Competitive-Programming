#include <bits/stdc++.h>
using namespace std;
int n;
void solve () {
    cin >> n;
    int ans = n * (n + 1) * (2 * n + 1) / 3 - n * (n + 1) / 2;
    cout << ans << " " << 2 * n << "\n";
    for (int i = 1; i <= n; i ++) {
        cout << "1 " << n - i + 1 << " ";
        for (int j = 1; j <= n; j ++)
            cout << j << " ";
        cout << "\n";
        cout << "2 " << n - i + 1 << " ";
        for (int j = 1; j <= n; j ++)
            cout << j << " ";
        cout << "\n";
    }
}
int main () {
    ios::sync_with_stdio (0);
    cin.tie (0);
    cout.tie (0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve ();
    }
    return 0;
}