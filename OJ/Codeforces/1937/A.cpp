#include <bits/stdc++.h>
using namespace std;
void solve () {
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++)
        if ((1 << i) <= n && (1 << (i + 1)) > n) {
            cout << (1 << i) << "\n";
            return ;
        }
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
    return 0;
}