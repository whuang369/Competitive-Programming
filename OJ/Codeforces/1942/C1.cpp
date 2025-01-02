#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int n;
int md (int x) {
    if (x <= 0)
        return x + n;
    return (x - 1) % n + 1;
}
int x, y;
void solve () {
    cin >> n >> x >> y;
    map <int, int> mp;
    vector <int> a(x + 1);
    for (int i = 1; i <= x; i ++) {
        cin >> a[i];
        mp[a[i]] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= x; i ++) {
        int nxt = mp[md(a[i])] + mp[md(a[i] - 1)] + mp[md(a[i] + 1)];
        int nxt2 = mp[md(a[i] - 2)] + mp[md(a[i] + 2)];
        int cur = x - nxt - 1 + nxt2;
        if (mp[md(a[i] - 1)] && !mp[md(a[i] - 2)]) {
            cur ++;
            if (mp[md(a[i] - 3)])
                cur ++;
        }
        if (mp[md(a[i] + 1)] && !mp[md(a[i] + 2)]) {
            cur ++;
            if (mp[md(a[i] + 3)])
                cur ++;
        }
        // if (cur == 4)
        //     cout << a[i] << "\n";
        ans = max (ans, cur);
    }
    cout << ans << "\n";
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