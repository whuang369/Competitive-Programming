#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 105;
int n, a[N];
void solve () {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    int rt = 0, l = 1, mx = 1;
    for (int i = 1; i < 2 * n; i ++) {
        if (a[i] > a[i + 1]) {
            mx = max (mx, i - l + 1);
            l = i + 1;
        }
    }
    mx = max (mx, 2 * n - l + 1);
    if (mx < n) {
        cout << "No\n";
    } else
        cout << "Yes\n";
    return ;
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