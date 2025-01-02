#include <bits/stdc++.h>
using namespace std;
int n, k;
void solve () {
    cin >> n >> k;
    int lft = k, sum = 0;
    for (int i = 1; i <= n; i ++) {
        if (lft <= 0)
            break;
        sum ++;
        lft -= n - i + 1;
        if (i == 1)
            continue ;
        if (lft <= 0)
            break ;
        sum ++;
        lft -= n - i + 1;
    }
    cout << sum << "\n";
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