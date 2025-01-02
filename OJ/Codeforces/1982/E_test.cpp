#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD = 1e9 + 7, N = 65;
ll n, k, Cc[N][N];
void init () {
    Cc[0][0] = 1;
    for (int i = 1; i <= 60; i ++)
        for (int j = 1; j <= 60; j ++)
            Cc[i][j] = (Cc[i - 1][j] + Cc[i - 1][j - 1]) % MOD;
}
ll C (ll x, ll y) {
    return Cc[x][y];
}
void solve () {
    cin >> n >> k;
    ll ans = 1;
    for (int len = 1; (1ll << len) < n; len ++) {
        for (int os = 2; os <= min (k, (ll)len); os ++)
            for (int ed = 0; ed <= len - os; ed ++) {
                if (os + ed < k)
                    continue ;
                ll tot = C (len - ed - 2, os - 2);
                ll sum = (1ll << (k - os))
            }
    }
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