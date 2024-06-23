#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], b[N];
void solve () {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    int mn = a[1];
    for (int i = 2; i <= n; i ++)
        mn = min (mn, a[i]); mn --;
    for (int i = 1; i <= q; i ++)
        cin >> b[i];
    for (int i = 1; i <= q; i ++)
        cout << min (mn, b[i]) << " ";
    cout << "\n";
    return ;
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