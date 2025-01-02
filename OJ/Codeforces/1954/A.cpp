#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve () {
    int n, m, k;
    cin >> n >> m >> k;
    int mxlft = n - (int)((n + m - 1) / m);
    if (mxlft <= k)
        cout << "NO\n";
    else
        cout << "YES\n";
    return ;
}
int main () {
    ios::sync_with_stdio (0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve ();
    }
    return 0;
}