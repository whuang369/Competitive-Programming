#include <bits/stdc++.h>
#define ll int
using namespace std;
const int N = 1e6 + 5;
ll n, k, a[N], fa[N];
ll cnt, pri[N], isp[N];
ll pri_cnt[N];
void init () {
    for (ll i = 2; i <= N - 5; i ++) {
        if (!isp[i]) {
            pri[++ cnt] = i;
            isp[i] = cnt;
        }
        for (ll j = 1; j <= cnt; j ++) {
            ll k = pri[j] * i;
            if (k > N - 5)
                break ;
            isp[k] = j;
            if (i % pri[j] == 0)
                break ;
        }
    }
}
vector <ll> pris (ll x) {
    vector <ll> ret;
    while (x != 1) {
        ll cur = pri[isp[x]];
        // cout << x << " " << cur << "333\n";
        ret.push_back(isp[x]);
        while (x % cur == 0)
            x /= cur;
        break ;
    }
    return ret;
}
ll find (ll x) {
    return (fa[x] == x ? x : fa[x] = find (fa[x]));
}
void merge (ll x, ll y) {
    ll xx = find (x), yy = find (y);
    if (xx == yy)
        return ;
    fa[xx] = yy;
    return ;
}
vector <ll> ps[N];
void solve () {
    cin >> n >> k;
    ll ans = 0;
    for (int i = 1; i <= cnt; i ++)
        ps[i].clear ();
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        a[i + n] = a[i];
    n *= 2;
    for (int i = 1; i <= n; i ++) {
        if (a[i] == 1 && i <= n)
            ans += n;
        fa[i] = i;
        if (a[i] == 1)
            continue ;
        vector <ll> cur = pris(a[i]);
        for (ll x : cur)
            ps[x].push_back(i);
    }
    for (int i = 1; i <= cnt; i ++) {
        if (ps[i].size() == 0)
            continue ;
        ll lst = -1;
        for (ll x : ps[i]) {
            if (lst != -1 && x - lst <= k)
                merge (x, lst);
            lst = x;
            continue ;
        }
    }
    for (int i = 1; i <= n; i ++)
        if (a[i] != 1 && find (i) == i)
            ans ++;
    cout << ans << "\n";
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