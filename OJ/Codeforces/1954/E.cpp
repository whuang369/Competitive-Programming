#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5, M = 1e5;
ll n, a[N], s[N], num[N], exi[N];
pair <ll, int> p[N];
void solve () {
    cin >> n;
    ll mx = -1;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        mx = max (mx, a[i]);
        p[i] = make_pair (a[i], i);
        exi[i] = 1;
    }
    sort (p + 1, p + n + 1);
    ll tpart = 1;
    ll lst = 0;
    s[0] = 1;
    for (int i = 1; i <= n; i ++) {
        int pos = p[i].second;
        if (pos == 1) {
            if (!exi[2])
                tpart --;
        } else if (pos == n) {
            if (!exi[n - 1])
                tpart --;
        } else {
            if (exi[pos - 1] && exi[pos + 1])
                tpart ++;
            else if (!exi[pos - 1] && !exi[pos + 1])
                tpart --;
        }
        exi[pos] = 0;
        if (p[i + 1].first == p[i].first)
            continue ;
        ll lstt = s[lst];
        while (lst < p[i].first) {
            s[lst] = lstt;
            lst ++;
        }
        s[p[i].first] = tpart;
    }
    // for (int i = 0; i <= mx; i ++)
    //     cout << s[i] << " ";
    // cout << "\n";
    for (ll k = 1; k <= mx; k ++) {
        ll cur = 0, ans = 0;
        lst = 0;
        while (cur < mx) {
            cur += k;
            ans += s[lst];
            lst = cur;
        }
        cout << ans << " ";
    }
}
int main () {
    ios::sync_with_stdio (0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        solve ();
    }
    return 0;
}