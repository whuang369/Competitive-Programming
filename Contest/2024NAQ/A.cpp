#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve () {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        if (x & 1)
            sum ++;
    }
    cout << sum << "\n";
}
int main () {
    ios::sync_with_stdio (0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        solve ();
    }
}