#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
ll n, m, a[N], s[N], nxt[N], ss[N];
void solve () {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    s[n + 1] = s[n] + m + 1;
    for (int i = 1; i <= n; i ++) {
        int l = i, r = n + 1, ans;
        while (l <= r) {
            int mid = (l + r) >> 1;
            ll sum = s[mid] - s[i - 1];
            if (sum <= m)
                l = mid + 1;
            else {
                ans = mid;
                r = mid - 1;
            }
        }
        nxt[i] = ans;
    }
    ss[n + 1] = 0;
    ll ans = 0;
    for (int i = n; i >= 1; i --) {
        if (nxt[i] == n + 1)
            ss[i] = n - i + 1;
        else
            ss[i] = nxt[i] - i + ss[nxt[i] + 1];
        ans += ss[i];
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
}