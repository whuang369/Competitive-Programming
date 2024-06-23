#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e3 + 5;
int n, a[N];
ll gcd (ll x, ll y) {
    return y == 0 ? x : gcd (y, x % y);
}
ll lcm (ll x, ll y) {
    return x / gcd (x, y) * y;
}
void solve () {
    set <ll> q;
    map <int, int> mp, mpa;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        mpa[a[i]] = 1;
    }
    sort (a + 1, a + n + 1);
    ll cur = 1, ok = 0;
    for (int i = 1; i <= n; i ++) {
        cur = lcm (cur, a[i]);
        if (cur > a[n]) {
            ok = 1;
            break ;
        }
    }
    if (ok || cur != a[n]) {
        cout << n << "\n";
        return ;
    }
    q.insert (-a[1]);
    mp[a[1]] = 1;
    int now = 2;
    ll ans = 0;
    while (now <= n) {
        for (ll x : q) {
            cur = lcm (a[now], -x);
            if (cur > a[n]) {
                ans = n;
                break ;
            }
            q.insert (-cur);
            mp[cur] = max (mp[cur], mp[-x] + 1);
            if (!mpa[cur])
                ans = max (ans, (ll)mp[cur]);
            // cout << -x << " ";
        }
        // cout << "\n";
        q.insert (-a[now]);
        mp[a[now]] = max (mp[a[now]], 1);
        if (ans == n)
            break ;
        now ++;
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