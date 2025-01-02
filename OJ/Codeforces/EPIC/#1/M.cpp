#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 105;
const ll MOD = 1e9 + 7;
ll n;
struct mex {
    ll a[N][N];
    void init () {
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                a[i][j] = 0;
        for (int i = 1; i <= n; i ++)
            a[i][i] = 1;
    }
    void mul (mex x) {
        ll ret[N][N];
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                ret[i][j] = 0;
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                for (int k = 1; k <= n; k ++) {
                    ret[i][j] += a[i][k] * x.a[k][j] % MOD;
                    ret[i][j] %= MOD;
                }
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                a[i][j] = ret[i][j];
    }
};
ll d[N], k, ls[N], b[N][N], s, t;
mex mxksm (mex x, ll y) {
    mex ret; ret.init ();
    mex now = x;
    while (y) { 
        if (y & 1) {
            ret.mul (now);
        }
        now.mul(now);
        y >>= 1;
    }
    return ret;
}
void solve () {
    cin >> n >> k;
    mex kk;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++) {
            cin >> b[i][j];
            kk.a[i][j] = b[i][j];
        }
    kk = mxksm (kk, k);
    cin >> s >> t;
    d[s] = 1;
        for (int j = 1; j <= n; j ++)
            ls[j] = 0;
        for (int j = 1; j <= n; j ++) {
            for (int l = 1; l <= n; l ++) {
                ls[j] += d[l] * kk.a[l][j] % MOD;
                ls[j] %= MOD;
            }
        }
        for (int j = 1; j <= n; j ++)
            d[j] = ls[j];
    cout << d[t] << "\n";
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        solve ();
    }
}