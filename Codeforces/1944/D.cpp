#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
const ll MOD[2] = {998244353, 1000000007}, B[2] = {103, 10003};
int n, q, lm_1[N], lm_2[N];
string s;
ll hashsum[N][2][2], pw[N][2];
void ori_init () {
    pw[0][0] = pw[0][1] = 1;
    for (int i = 1; i <= N - 5; i ++) {
        pw[i][0] = pw[i - 1][0] * B[0] % MOD[0];
        pw[i][1] = pw[i - 1][1] * B[1] % MOD[1];
    }
    return ;
}
void init () {
    hashsum[0][0][0] = hashsum[0][0][1] = s[0];
    for (int i = 1; i < n; i ++) {
        hashsum[i][0][0] = (hashsum[i - 1][0][0] * B[0] + s[i]) % MOD[0];
        hashsum[i][0][1] = (hashsum[i - 1][0][1] * B[1] + s[i]) % MOD[1];
    }
    hashsum[n - 1][1][0] = hashsum[n - 1][1][1] = s[n - 1];
    for (int i = n - 2; i >= 0; i --) {
        hashsum[i][1][0] = (hashsum[i + 1][1][0] * B[0] + s[i]) % MOD[0];
        hashsum[i][1][1] = (hashsum[i + 1][1][1] * B[1] + s[i]) % MOD[1];
    }
}
pair <ll, ll> get_val (ll l, ll r, ll dir) {
    if (dir == 0) {
        ll ret[2];
        ret[0] = hashsum[r][0][0] - (l == 0 ? 0 : hashsum[l - 1][0][0]) * pw[r - l + 1][0] % MOD[0];
        ret[0] %= MOD[0];
        if (ret[0] < 0)
            ret[0] += MOD[0];
        ret[1] = hashsum[r][0][1] - (l == 0 ? 0 : hashsum[l - 1][0][1]) * pw[r - l + 1][1] % MOD[1];
        ret[1] %= MOD[1];
        if (ret[1] < 0)
            ret[1] += MOD[1];
        return make_pair (ret[0], ret[1]);
    } else {
        ll ret[2];
        ret[0] = hashsum[l][1][0] - (r == n - 1 ? 0 : hashsum[r + 1][1][0]) * pw[r - l + 1][0] % MOD[0];
        ret[0] %= MOD[0];
        if (ret[0] < 0)
            ret[0] += MOD[0];
        ret[1] = hashsum[l][1][1] - (r == n - 1 ? 0 : hashsum[r + 1][1][1]) * pw[r - l + 1][1] % MOD[1];
        ret[1] %= MOD[1];
        if (ret[1] < 0)
            ret[1] += MOD[1];
        return make_pair (ret[0], ret[1]);
    }
}
void same_init () {
    lm_1[0] = 0;
    for (int i = 1; i < n; i ++)
        lm_1[i] = (s[i] == s[i - 1] ? lm_1[i - 1] : i);
    lm_2[0] = 0;
    lm_2[1] = 1;
    for (int i = 2; i < n; i += 2)
        lm_2[i] = (s[i] == s[i - 2] ? lm_2[i - 2] : i);
    for (int i = 3; i < n; i += 2)
        lm_2[i] = (s[i] == s[i - 2] ? lm_2[i - 2] : i);
    return ;
}
void solve () {
    cin >> n >> q >> s;
    init ();
    same_init ();
    while (q --) {
        int l, r;
        cin >> l >> r;
        ll badsum = 0, len = r - l + 1;
        r --, l --;
        if (lm_1[r] <= l)
            badsum = (len * (len + 1) / 2);
        else {
            int l1 = ((l & 1) ? l : l + 1), l0 = (!(l & 1) ? l : l + 1);
            int r1 = ((r & 1) ? r : r - 1), r0 = (!(r & 1) ? r : r - 1);
            if (lm_2[r1] <= l1 && lm_2[r0] <= l0) {
                ll len1 = len - (1 - len % 2);
                len1 = (len + 1) / 2;
                badsum += len1 * len1;
            } else {
                if (get_val(l, r, 0) == get_val(l, r, 1))
                    badsum += len;
                badsum ++;
            }
        }
        ll ans = len * (len + 1) / 2 - badsum;
        // cout << badsum << " ";
        cout << ans << "\n";
        // if (n == 12) {
        //     cout << get_val(l, r, 0).first << ":" << get_val(l, r, 0).second << "\n";
        //     cout << get_val(l, r, 1).first << ":" << get_val(l, r, 1).second << "\n";
        // }
    }
}
int main () {
    ori_init();
    ios::sync_with_stdio (0);
    cin.tie (0);
    cout.tie (0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve ();
    }
}