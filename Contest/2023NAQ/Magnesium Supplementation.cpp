#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
ll cnt, pri[N], isp[N];
void init () {
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
}
ll n, l, r;
void solve () {
    cin >> n >> r >> l;
    l = (n + l - 1) / l;
    if (l > r) {
        cout << "0\n";
        return ;
    }
    ll now = n;
    vector <pair <ll, int> > v;
    for (int i = 1; i <= cnt; i ++) {
        if (now % pri[i])
            continue ;
        pair <ll, int> p;
        p.first = pri[i];
        p.second = 0;
        while (!(now % pri[i])) {
            now /= pri[i];
            p.second = p.second + 1;
        }
        v.push_back (p);
        if (now == 1)
            break ;
    }
    if (now != 1)
        v.push_back (make_pair (now, 1));
    set <ll> divs;
    divs.insert (1);
    set <ll> ls;
    for (auto p : v) {
        ll num = p.first, tims = p.second;
        ls.clear ();
        for (ll x : divs) {
            ll cur = 1;
            for (int i = 1; i <= tims; i ++) {
                cur *= num;
                ls.insert (cur * x);
            }
        }
        for (ll x : ls)
            divs.insert (x);
    }
    vector <ll> ans;
    for (ll x : divs) {
        if (x > r)
            break ;
        if (x >= l)
            ans.push_back (x);
    }
    cout << ans.size() << "\n";
    for (ll x : ans) {
        cout << x << "\n";
    }
    return ;
}
int main () {
    init ();
    ios::sync_with_stdio (0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        solve ();
    }
}