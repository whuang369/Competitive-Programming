#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
const ll MOD = 1e9 + 7;
ll n, cnt, pw[N], inv[N], inv_n[N], pri[N], isp[N], pcnt[N];
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
ll C (ll i, ll k) {
    if (i < k)
        return 0;
    // cout << i << " " << k << " " << pw[i] << " " << inv[i - k] << " " << inv_n[k] << "\n";
    return pw[i] * inv[i - k] % MOD * inv_n[k] % MOD;
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
        // tim += cnt;
        for (ll j = 1; j <= cnt; j ++) {
            ll k = pri[j] * i;
            if (k > N - 5)
                break ;
            isp[k] = 1;
            if (i % pri[j] == 0)
                break ;
        }
        pcnt[i] = cnt;
        tim += pcnt[(int)sqrt (i)];
    }
    // cout << tim << "\n";
    return ;
}
ll l_ans = 0;
void solve () {
    ll n;
    cin >> n;
    ll ans = 0;
    // pri[0] = 4;
    ll inv_2 = ksm (2, MOD - 2);
    for (int i = 1; pri[i] <= n; i ++) {
        ll p = pri[i];
        ll mxm = n / pri[i];
        ll prid = (p - 1) * (p - 1) % MOD * (p - 2) % MOD * inv_2 % MOD;
        ll totpart = mxm / p;
        ll lftpart = mxm % p;
        ll cur = 0;
        cur += prid * totpart % MOD;
        cur %= MOD;
        cur *= p;
        cur %= MOD;
        cur += (p - 1) * (lftpart + 1) % MOD * lftpart % MOD * inv_2 % MOD;
        cur %= MOD;
        ans += cur;
        ans %= MOD;
        if (n <= 100)
            cout << p << ":" << cur << "\n";
    }
    cout << ans << "\n";
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