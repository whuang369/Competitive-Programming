#include <bits/stdc++.h>
#define F first
#define S second
#define mk make_pair
#define ll long long
using namespace std;
const ll MOD[2] = {998244353, 1000000007};
const ll p[2] = {23, 103};
const int N = 2e5 + 5;
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
void init (ll n, string s) {
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
int nums[N][3], pos[N];
void solve () {
    cin >> s;
    n = s.size();
    string t = "";
    for (int i = 0; i < n; i ++)
        if (s[i] != 'a') {
            t += s[i];
            pos[t.size() - 1] = i;
        }
    n = t.size();
    if (n == 0) {
        n = s.size();
        cout << n - 1 << "\n";
        return ;
    }
    init (n, t);
    vector <vector <pair <int, int> > > psv;
    for (int len = 1; len <= n; len ++) {
        if (n % len)
            continue ;
        int ok = 1;
        for (int j = 0; j < t.size(); j += len)
            if (subs (j, j + len - 1, 0, 0) != subs (0, len - 1, 0, 0) 
            || subs (j, j + len - 1, 0, 1) != subs (0, len - 1, 0, 1)) {
                ok = 0;
                break ;
            }
        int lens = 0, lst = 0, x = s.size(), y = s.size(), z = s.size();
        vector <pair <int, int> > tempv;
        for (int j = 0; j < t.size(); j += len) {
            int l = j, r = j + len - 1;
            if (pos[r] - pos[l] + 1 != lens && lens != 0) {
                ok = 0;
                break ;
            }
            tempv.push_back (mk (pos[l], pos[r]));
            if (lens == 0)
                x = pos[j];
            else
                y = min (y, pos[l] - lst - 1);
            lens = pos[r] - pos[l] + 1;
            lst = pos[r];
        }
        z = s.size() - lst - 1;
        if (!ok)
            continue;
        nums[psv.size()][0] = x;
        nums[psv.size()][1] = y;
        nums[psv.size()][2] = z;
        psv.push_back (tempv);
    }
    n = s.size();
    init (n, s);
    ll ans = 0, i = 0;
    for (auto vx : psv) {
        int ok = 1;
        for (int j = 1; j < vx.size(); j ++) {
            if (subs(vx[0].first, vx[0].second, 0, 0) != subs(vx[j].first, vx[j].second, 0, 0) || 
                subs(vx[0].first, vx[0].second, 0, 1) != subs(vx[j].first, vx[j].second, 0, 1)) {
                    ok = 0;
                    break ;
                }
        }
        // for (int j = vx[0].first; j <= vx[0].second; j ++)
        //     cout << s[j];
        ll x = nums[i][0], y = nums[i][1], z = nums[i][2];
        x = min (x, y);
        z = min (z, y);
        y = min (x + z, y);
        // cout << ":" << x << " " << y << " " << z;
        i ++;
        if (!ok)
            continue ;
        ll sum = 0;
        for (ll l = 0; l <= x; l ++)
            sum += min (y - l + 1, z + 1);
        ans += sum;
        // cout << " " << sum << "\n";
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
}