#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, k;
void solve () {
    cin >> n >> k;
    int cur = 1;
    while ((1 << cur) - 1 < k)
        cur ++;
    cur --;
    if (n == 1) {
        cout << k << "\n";
        return ;
    }
    int ans2 = (1 << cur) - 1;
    cout << k - ans2 << " " << ans2 << " ";
    for (int i = 3; i <= n; i ++)
        cout << "0 ";
    cout << "\n";
}
int T;
int main () {
    ios::sync_with_stdio (false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T --) {
        solve ();
    }
}