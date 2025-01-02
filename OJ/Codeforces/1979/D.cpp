#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD[2] = {998244353, 1000000007};
const ll p[2] = {23, 103};
const int N = 1e5 + 5;
ll pw[N][2], totk[2], mulk[2], rev[2], inv[N][2], ss[N][2][2];
ll ksm (ll x, ll y, ll m) {
    ll ret = 1, now = x;
    while (y) {
        if (y & 1) {
            ret *= now;
            ret %= m;
        }
        now *= now;
        now %= m;
        y >>= 1;
    }
    return ret;
}
void init (ll n, ll k, string s) {
    pw[0][0] = pw[0][1] = 1;
    for (ll i = 1; i <= n; i ++) {
        pw[i][0] = pw[i - 1][0] * p[0] % MOD[0];
        pw[i][1] = pw[i - 1][1] * p[1] % MOD[1];
    }
    inv[n][0] = ksm (pw[n][0], MOD[0] - 2, MOD[0]);
    inv[n][1] = ksm (pw[n][1], MOD[1] - 2, MOD[1]);
    for (ll i = n; i >= 1; i --) {
        inv[i - 1][0] = inv[i][0] * p[0] % MOD[0];
        inv[i - 1][1] = inv[i][1] * p[1] % MOD[1];
    }
    mulk[0] = mulk[1] = 0;
    for (ll i = 0; i < n; i += 2 * k) {
        mulk[0] += pw[i][0];
        mulk[0] %= MOD[0];
        mulk[1] += pw[i][1];
        mulk[1] %= MOD[1];
    }
    totk[0] = totk[1] = 0;
    for (ll i = k; i < n; i += 2 * k) {
        totk[0] += pw[i][0];
        totk[0] %= MOD[0];
        totk[1] += pw[i][1];
        totk[1] %= MOD[1];
    }
    rev[0] = rev[1] = 0;
    for (ll i = 0; i < k; i ++)
        for (ll j = 0; j < 2; j ++) {
            rev[j] += pw[i][j];
            rev[j] %= MOD[j];
        }
    ss[0][0][0] = ss[0][0][1] = s[0] - '0';
    for (ll i = 1; i < n; i ++)
        for (ll j = 0; j < 2; j ++)
            ss[i][0][j] = (ss[i - 1][0][j] + pw[i][j] * (s[i] - '0') % MOD[j]) % MOD[j];
    ss[n - 1][1][0] = ss[n - 1][1][1] = s[n - 1] - '0';
    for (ll i = n - 2; i >= 0; i --)
        for (ll j = 0; j < 2; j ++)
            ss[i][1][j] = (ss[i + 1][1][j] + pw[n - 1 - i][j] * (s[i] - '0') % MOD[j]) % MOD[j];
}
ll kpp (ll x, ll t) {
    return (x * mulk[t] % MOD[t] + (rev[t] - x < 0 ? rev[t] - x + MOD[t] : rev[t] - x) * totk[t] % MOD[t]) % MOD[t];
}
ll n, k;
string s;
ll subs (ll l, ll r, ll dir, ll t) {
    ll ret = 0;
    if (dir) {
        ret = 0;
        ret += ss[l][1][t];
        if (r != n - 1)
            ret -= ss[r + 1][1][t];
        if (ret < 0)
            ret += MOD[t];
        ret *= inv[n - 1 - r][t];
        ret %= MOD[t];
    } else {
        ret = 0;
        ret += ss[r][0][t];
        if (l != 0)
            ret -= ss[l - 1][0][t];
        if (ret < 0)
            ret += MOD[t];
        ret *= inv[l][t];
        ret %= MOD[t];
    }
    return ret;
}
void solve () {
    cin >> n >> k;
    cin >> s;
    init (n, k, s);
    string t = s;
    for (ll len = 1; len <= n; len ++) {
        ll new_fir_k[2] = {0, 0};
        ll rk[2] = {0, 0};
        if (n - len < k) {
            if (len != n) {
                new_fir_k[0] = subs (len, n - 1, 0, 0);
                new_fir_k[1] = subs (len, n - 1, 0, 1);
            }
            ll lft = k - (n - len);
            new_fir_k[0] += subs (len - lft, len - 1, 1, 0) * pw[n - len][0] % MOD[0];
            new_fir_k[0] %= MOD[0];
            new_fir_k[1] += subs (len - lft, len - 1, 1, 1) * pw[n - len][1] % MOD[1];
            new_fir_k[1] %= MOD[1];
        } else {
            new_fir_k[0] += subs (len, len + k - 1, 0, 0);
            new_fir_k[1] += subs (len, len + k - 1, 0, 1);
        }
        ll shd[2] = {0, 0};
        shd[0] = mulk[0] * new_fir_k[0] % MOD[0];
        shd[1] = mulk[1] * new_fir_k[1] % MOD[1];
        rk[0] = rev[0] - new_fir_k[0] + MOD[0];
        rk[0] %= MOD[0];
        rk[1] = rev[1] - new_fir_k[1] + MOD[1];
        rk[1] %= MOD[1];
        if (new_fir_k[0] != 0 && new_fir_k[1] != 0 && rk[0] != 0 && rk[1] != 0) {
            continue ;
        }
        shd[0] += totk[0] * rk[0] % MOD[0];
        shd[0] %= MOD[0];
        shd[1] += totk[1] * rk[1] % MOD[1];
        shd[1] %= MOD[1];
        ll aft[2] = {0, 0};
        aft[0] = (n == len ? 0 : subs(len, n - 1, 0, 0)) + subs(0, len - 1, 1, 0) * pw[n - len][0] % MOD[0];
        aft[0] %= MOD[0];
        aft[1] = (n == len ? 0 : subs(len, n - 1, 0, 1)) + subs(0, len - 1, 1, 1) * pw[n - len][1] % MOD[1];
        aft[1] %= MOD[1];
        if (shd[0] == aft[0] && shd[1] == aft[1]) {
            cout << len << "\n";
            return ;
        }
    }
    cout << "-1\n";
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