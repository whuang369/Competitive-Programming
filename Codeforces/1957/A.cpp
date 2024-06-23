#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, a[N], cnt[N];
void solve () {
    memset (cnt, 0, sizeof (cnt));
    cin >> n;
    set <int> s;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        cnt[a[i]] ++;
        s.insert (a[i]);
    }
    int ans = 0;
    for (int x : s) {
        ans += cnt[x] / 3;
    }
    cout << ans << "\n";
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