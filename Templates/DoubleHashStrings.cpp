#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD[2] = {998244353, 1000000007};
const ll p[2] = {23, 103};
const int N = 1e5 + 5;
ll pw[N][2], inv[N][2], ss[N][2][2];
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
    ss[0][0][0] = ss[0][0][1] = s[0] - '0';
    for (ll i = 1; i < n; i ++)
        for (ll j = 0; j < 2; j ++)
            ss[i][0][j] = (ss[i - 1][0][j] + pw[i][j] * (s[i] - '0') % MOD[j]) % MOD[j];
    ss[n - 1][1][0] = ss[n - 1][1][1] = s[n - 1] - '0';
    for (ll i = n - 2; i >= 0; i --)
        for (ll j = 0; j < 2; j ++)
            ss[i][1][j] = (ss[i + 1][1][j] + pw[n - 1 - i][j] * (s[i] - '0') % MOD[j]) % MOD[j];
}
string s;
int n;
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
    cin >> s;
    n = s.size();
    int q = 0;
    cin >> q;
    while (q --) {
        int l1, r1, dir1, l2, r2, dir2;
        cin >> l1 >> r1 >> dir1 >> l2 >> r2 >> dir2;
        ll mk1[2] = {subs (l1 + 1, r1 + 1, dir1, 0), subs (l1 + 1, r1 + 1, dir1, 1)};
        ll mk2[2] = {subs (l2 + 1, r2 + 1, dir2, 0), subs (l2 + 1, r2 + 1, dir2, 1)};
        if (mk1[0] != mk2[0] || mk1[1] != mk2[1])
            cout << "Not Equal!\n";
        else
            cout << "Equal!\n";
    }
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
