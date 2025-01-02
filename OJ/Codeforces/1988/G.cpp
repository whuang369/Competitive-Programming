#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 5;
int isp[N], cnt, pri[N], psum[N];
int gcd (int x, int y) {
    if (!y)
        return x;
    else
        return gcd (y, x % y);
}
void solve () {
    ll a, b;
    cin >> a >> b;
    if (a < b)
        swap (a, b);
    ll ans = 0;
    for (ll x = 1; x <= a; x ++) {
        if (isp[x])
            continue ;
        if (x <= b) {
            ans += x + 1;
            continue ;
        }
        ll mn = b * (a - x) / (a - b);
        // cout << x << ":" << mn << "\n";
        ans += mn + 1;
    }
    cout << ans << "\n";
}
void init () {
    int n = N - 5;
    isp[0] = isp[1] = 1;
    for (int i = 2; i <= n; i ++) {
        if (!isp[i])
            pri[++ cnt] = i;
        psum[i] = psum[i - 1];
        if (!isp[i])
            psum[i] ++;
        for (int j = 1; j <= cnt; j ++) {
            int cur = i * pri[j];
            if (cur > n)
                break ;
            isp[cur] = 1;
            if (i % pri[j] == 0)    
                break ;
        }
    }
}
int main () {
    init ();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        solve ();
    }
}