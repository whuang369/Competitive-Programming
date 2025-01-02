#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
string s;
int d[N], tr[N << 2], lnxt[N];
void pushup (int t) {
    tr[t] = max (tr[t << 1], tr[t << 1 | 1]);
}
void build (int l, int r, int t) {
    if (l == r) {
        tr[t] = d[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build (l, mid, t << 1);
    build (mid + 1, r, t << 1 | 1);
    pushup (t);
}
int query (int l, int r, int ql, int qr, int t) {
    if (ql <= l && r <= qr) {
        return tr[t];
    }
    int ret = -1;
    int mid = (l + r) >> 1;
    if (ql <= mid)
        ret = max (ret, query (l, mid, ql, qr, t << 1));
    if (mid < qr)
        ret = max (ret, query (mid + 1, r, ql, qr, t << 1 | 1));
    return ret;
}
void solve () {
    cin >> s;
    int n = s.size ();
    s = ' ' + s;
    for (int i = 1; i <= n; i ++) {
        d[i] = d[i - 1] + (s[i] == '(' ? 1 : -1);
        lnxt[i] = 0;
    }
    lnxt[n + 1] = -1;
    build (1, n, 1);
    map <int, int> mp;
    int cnt = 0;
    ll ans = 0;
    for (int i = n; i >= 1; i --) {
        int lst = mp[d[i]];
        if (lst == 0)
            lst = n + 1;
        mp[d[i]] = i;
        if (query (1, n, i + 1, lst - 1, 1) > 2 * d[i])
            lnxt[i] = 0;
        else
            lnxt[i] = lnxt[lst] + 1;
        ans += lnxt[i];
        // cout << lnxt[i] << " ";
    }
    // cout << "\n";
    cout << ans << "\n";
}
int main () {
    ios::sync_with_stdio (0);
    cin.tie (0);
    cout.tie (0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve ();
    }
}