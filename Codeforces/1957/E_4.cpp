#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
const ll MOD = 1e9 + 7;
ll cnt, pw[N], inv[N], inv_n[N], pri[N], isp[N], pcnt[N];
ll diff[N], ans[N];
ll ksm (ll x, ll y) {
    ll ret = 1, now = x;
    while (y) {
        if (y & 1) {
            ret *= now;
            ret %= MOD;
        }
        now *= now;
        now %= MOD;
        y >>= 1;
    }
    return ret;
}
void init () {
    pw[0] = inv[0] = 1;
    for (ll i = 1; i <= N - 5; i ++)
        pw[i] = pw[i - 1] * i % MOD;
    inv[N - 5] = ksm (pw[N - 5], MOD - 2);
    inv_n[N - 5] = ksm (N - 5, MOD - 2);
    for (ll i = N - 6; i >= 0; i --) {
        inv[i] = inv[i + 1] * (i + 1) % MOD;
        inv_n[i] = inv[i] * pw[i - 1] % MOD;
    }
    ll tim = 0;
    for (ll i = 2; i <= N - 5; i ++) {
        if (!isp[i])
            pri[++ cnt] = i;
        for (ll j = 1; j <= cnt; j ++) {
            ll k = pri[j] * i;
            if (k > N - 5)
                break ;
            isp[k] = 1;
            if (i % pri[j] == 0)
                break ;
        }
    }
    for (int i = 1; i <= cnt; i ++)
        for (int j = 1; j * pri[i] <= N - 5; j ++) {
            if (j % pri[i] == 0)
                continue ;
            diff[j * pri[i]] += pri[i] - (j % pri[i]);
            diff[j * pri[i]] %= MOD;
            if ((j + 1) * pri[i] <= N - 5) {
                diff[(j + 1) * pri[i]] -= pri[i] - (j % pri[i]);
                diff[(j + 1) * pri[i]] %= MOD;
                if (diff[(j + 1) * pri[i]] < 0)
                    diff[(j + 1) * pri[i]] += MOD;
            }
        }
        for (int j = 1; j * 4 <= N - 5; j += 2) {
            if (j % 4 == 0)
                continue ;
            diff[j * 4] += 2;
            diff[j * 4] %= MOD;
            if ((j + 1) * 4 <= N - 5) {
                diff[(j + 1) * 4] -= 2;
                diff[(j + 1) * 4] %= MOD;
                if (diff[(j + 1) * 4] < 0)
                    diff[(j + 1) * 4] += MOD;
            }
        }
    ll sum = 0;
    for (int i = 1; i <= N - 5; i ++) {
        sum += diff[i];
        sum %= MOD;
        if (sum < 0)
            sum += MOD;
        ans[i] = ans[i - 1] + sum;
        ans[i] %= MOD;
    }
    cout << "\n";
    return ;
}
void solve () {
    ll n;
    cin >> n;
    cout << ans[n] << "\n";
}
int main () {
    init ();
    ios::sync_with_stdio (0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve ();
    }
    return 0;
}