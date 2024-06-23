#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, a[N];
void init() {
    int now = 0, mx = 0;
    for (int i = 1; i <= 1000; i ++) {
        a[i] = i;
        if (i >= 1)
            a[i] = min (a[i], a[i - 1] + 1);
        if (i >= 3)
            a[i] = min (a[i], a[i - 3] + 1);
        if (i >= 6)
            a[i] = min (a[i], a[i - 6] + 1);
        if (i >= 10)
            a[i] = min (a[i], a[i - 10] + 1);
        if (i >= 15)
            a[i] = min (a[i], a[i - 15] + 1);
        if (i < 15)
            continue ;
        if (a[i] == a[i - 15] + 1) {
            now ++;
        } else
            now = 0;
        mx = max (mx, now);
    }
    return;
}
void solve() {
    cin >> n;
    int ans = 0;
    if (n >= 38) {
        ans += (n - 38) / 15;
        n -= ans * 15;
    }
    ans += a[n];
    cout << ans << "\n";
}
int main () {
    init ();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve ();
    }
}