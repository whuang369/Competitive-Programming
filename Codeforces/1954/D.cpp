#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e3 + 5;
const ll MOD = 998244353;
ll n, a[N], d[N], plan[N], plan2[N];
void solve () {
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    memset (d, 0, sizeof (d));
    memset (plan, 0, sizeof (plan));
    sort (a + 1, a + n + 1);
    plan[0] = 1;
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j <= 5000; j ++) {
            plan2[j] = 0;
            if (!plan[j])
                continue ;
            if (j <= a[i]) {
                ans += (ll)plan[j] * (ll)a[i] % MOD;
                ans %= MOD;
            } else {
                ans += (ll)(plan[j]) * (ll)((j + a[i] + 1) / 2) % MOD;
                ans %= MOD;
            }
        }
        for (int j = 0; j <= 5000; j ++) {
            plan2[j + a[i]] += plan[j];
            plan2[j + a[i]] %= MOD;
        }
        for (int j = 0; j <= 5000; j ++)
            plan[j] += plan2[j];
    }
    cout << ans << "\n";
    return ;
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