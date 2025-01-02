#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
const ll p[2] = {29, 31}, MOD[2] = {1e9 + 7, 998244353};
ll n, hashs[N][2][2], pp[N][2], mxr[N], mnl[N];
ll tr[N << 2][2], tag[N << 2][2];
void init () {
    pp[0][0] = pp[0][1] = 1;
    for (int i = 1; i <= N - 5; i ++) {
        pp[i][0] = pp[i - 1][0] * p[0] % MOD[0];
        pp[i][1] = pp[i - 1][1] * p[1] % MOD[1];
    }
    return ;
}
ll get_val (int l, int r, int rev, int base) {
    if (rev) {
        ll ret = hashs[l][rev][base];
        if (r != n - 1)
            ret -= hashs[r + 1][rev][base] * pp[r - l + 1][base] % MOD[base];
        ret %= MOD[base];
        if (ret < 0)
            ret += MOD[base];
        return ret;
    } else {
        ll ret = hashs[r][rev][base];
        if (l != 0)
            ret -= hashs[l - 1][rev][base] * pp[r - l + 1][base] % MOD[base];
        ret %= MOD[base];
        if (ret < 0)
            ret += MOD[base];
        return ret;
    }
}
void build (int l, int r, int t, int rev) {
    if (l == r) {
        tr[t][rev] = -1;
        return ;
    }
    int mid = (l + r) >> 1;
    build (l, mid, t << 1, rev);
    build (mid + 1, r, t << 1 | 1, rev);
    return ;
}
void pushdown (int l, int r, int t, int rev) {
    if (tag[t][rev] == -1)
        return ;
    tr[t][rev] = tag[t][rev];
    if (l == r) {
        tag[t][rev] = -1;
        return ;
    }
    tag[t << 1][rev] = tag[t][rev];
    tag[t << 1 | 1][rev] = tag[t][rev];
    tag[t][rev] = -1;
    return ;
}
void modify (int l, int r, int ql, int qr, int val, int t, int rev) {
    if (l >= ql && r <= qr) {
        tr[t][rev] = tag[t][rev] = val;
        pushdown (l, r, t, rev);
        return ;
    }
    int mid = (l + r) >> 1;
    if (ql <= mid)
        modify (l, mid, ql, qr, val, t << 1, rev);
    if (mid < qr)
        modify (mid + 1, r, ql, qr, val, t << 1 | 1, rev);
    return ;
}
ll query (int l, int r, int pos, int t, int rev) {
    if (l == r) {
        return tr[t][rev];
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        return query (l, mid, pos, t << 1, rev);
    else
        return query (mid + 1, r, pos, t << 1 | 1 , rev);
}
void solve () {
    string s;
    cin >> n >> s;
    for (int k = 0; k < 2; k ++) {
        hashs[0][0][k] = s[0] - '0';
        for (int i = 1; i < n; i ++) {
            hashs[i][0][k] = hashs[i - 1][0][k] * p[k] % MOD[k] + s[i] - '0';
            hashs[i][0][k] %= MOD[k];
        }
        hashs[n - 1][1][k] = s[n - 1] - '0';
        for (int i = n - 2; i >= 0; i --) {
            hashs[i][1][k] = hashs[i + 1][1][k] * p[k] % MOD[k] + s[i] - '0';
            hashs[i][1][k] %= MOD[k];
        }
    }
    for (int i = 0; i < n - 1; i ++) {
        if (s[i] != s[i + 1]) {
            mxr[i] = -1;
            continue ;
        }
        int l = 0, r = i;
        
    }
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init ();
    int T = 1;
    // cin >> T;
    while (T --) {
        solve ();
    }
}