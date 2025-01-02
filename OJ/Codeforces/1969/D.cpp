#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
ll n, k, a[N], b[N], c[N], p[N], s[N];
bool cmp (int x, int y) {
    return (b[x] == b[y] ? a[x] < a[y] : b[x] > b[y]);
}
void solve () {
    cin >> n >> k;
    ll sum = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i ++) {
        cin >> b[i];
        c[i] = b[i] - a[i];
        p[i] = i;
    }
    sort (p + 1, p + n + 1, cmp);
    ll ans = 0;
    p[n + 1] = 0;
    priority_queue <ll> q;
    for (int i = 1; i <= k; i ++) {
        sum += a[p[i]];
        q.push (a[p[i]]);
    }
    for (int i = n; i >= 1; i --)
        s[p[i]] = max (c[p[i]], 0ll) + s[p[i + 1]];
    ans = max (ans, -sum + s[p[k + 1]]);
    for (int i = k + 1; i <= n; i ++) {
        q.push (a[p[i]]);
        sum += a[p[i]];
        sum -= q.top ();
        q.pop ();
        // if (i != n && b[p[i]] == b[p[i + 1]])
        //     continue ;
        ans = max (ans, -sum + s[p[i + 1]]);
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