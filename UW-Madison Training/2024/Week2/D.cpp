#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
int tr[N << 2], a[N];
set <int> s;
map <int, int> mp;
void pushup (int t) {
    tr[t] = tr[t << 1] + tr[t << 1 | 1];
    return ;
}
void build (int l, int r, int t) {
    if (l == r) {
        tr[t] = 0;
        return ;
    }
    int mid = (l + r) >> 1;
    build (l, mid, t << 1);
    build (mid + 1, r, t << 1 | 1);
    tr[t] = 0;
    return ;
}
void upd (int pos, int l, int r, int t) {
    if (l == r) {
        tr[t] ++;
        return ;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        upd (pos, l, mid, t << 1);
    else
        upd (pos, mid + 1, r, t << 1 | 1);
    pushup (t);
    return ;
}
int query (int ql, int qr, int l, int r, int t) {
    if (ql <= l && r <= qr) {
        return tr[t];
    }
    int ret = 0, mid = (l + r) >> 1;
    if (ql <= mid)
        ret += query (ql, qr, l, mid, t << 1);
    if (mid < qr)
        ret += query (ql, qr, mid + 1, r, t << 1 | 1);
    return ret;
}
int n;
ll sum;
void solve () {
    cin >> n;
    build (1, n, 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        s.insert (a[i]);
    }
    int now = 1;
    for (auto x : s) {
        mp[x] = now ++;
    }
    for (int i = 1; i <= n; i ++) {
        int x = mp[a[i]];
        sum += query (x, n, 1, n, 1);
        upd (x, 1, n, 1);
    }
    cout << sum << "\n";
}
int main () {
    ios::sync_with_stdio (0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        solve ();
    }
}