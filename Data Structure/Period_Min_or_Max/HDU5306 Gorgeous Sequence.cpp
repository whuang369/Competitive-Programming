#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
ll n, q, a[N], tr_max[N << 2][3], tr_sum[N << 2], tag[N << 2];
void init () {}
bool opt (int l, int r, int t) {
    if (tr_max[t][0] <= tag[t])
        return true;
    if (tr_max[t][1] >= tag[t])
        return false;
    tr_sum[t] -= (tr_max[t][0] - tag[t]) * (r - l + 1);
    tr_max[t][0] = tag[t];
    return true;
}
void pushup (int l, int r, int t);
void pushdown (int l, int r, int t) {
    if (tag[t] == -1)
        return ;
    if (!opt (l, r, t)) {
        if (tag[t << 1] != -1)
            tag[t << 1] = min (tag[t << 1], tag[t]);
        else
            tag[t << 1] = tag[t];
        if (tag[t << 1 | 1] != -1)
            tag[t << 1 | 1] = min (tag[t << 1 | 1], tag[t]);
        else
            tag[t << 1 | 1] = tag[t];
        tag[t] = -1;
        int mid = (l + r) >> 1;
        pushdown (l, mid, t << 1);
        pushdown (mid + 1, r, t << 1 | 1);
        pushup (l, r, t);
    } else {
        if (l == r) {
            tag[t] = -1;
            return ;
        }
        tag[t << 1] = min (tag[t << 1], tag[t]);
        tag[t << 1 | 1] = min (tag[t << 1 | 1], tag[t]);
        if (tag[t << 1] != -1)
            tag[t << 1] = min (tag[t << 1], tag[t]);
        else
            tag[t << 1] = tag[t];
        if (tag[t << 1 | 1] != -1)
            tag[t << 1 | 1] = min (tag[t << 1 | 1], tag[t]);
        else
            tag[t << 1 | 1] = tag[t];
        tag[t] = -1;
    }
}
void pushup (int l, int r, int t) {
    if (tag[t] != -1)
        pushdown (l, r, t);
    if (l == r)
        return ;
    int mid = (l + r) >> 1;
    pushdown (l, mid, t << 1);
    pushdown (mid + 1, r, t << 1 | 1);
    vector <ll> v;
    v.push_back (tr_max[t << 1][0]);
    v.push_back (tr_max[t << 1][1]);
    v.push_back (tr_max[t << 1 | 1][0]);
    v.push_back (tr_max[t << 1 | 1][1]);
    sort (v.begin(), v.end());
    tr_max[t][0] = v[3];
    tr_max[t][1] = v[2];
    tr_max[t][2] = 0;
    if (v[3] == tr_max[t << 1][0])
        tr_max[t][2] += tr_max[t << 1][2];
    if (v[3] == tr_max[t << 1 | 1][0])
        tr_max[t][2] += tr_max[t << 1 | 1][2];
    tr_sum[t] = tr_sum[t << 1] + tr_sum[t << 1 | 1];
}
void build (int l, int r, int t) {
    tag[t] = -1;
    if (l == r) {
        tr_max[t][0] = a[l];
        tr_max[t][1] = -1;
        tr_max[t][2] = 1;
        tr_sum[t] = a[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build (l, mid, t << 1);
    build (mid + 1, r, t << 1 | 1);
    pushup (l, r, t);
}
void modify (int l, int r, int ql, int qr, ll val, int t) {
    pushdown (l, r, t);
    if (ql <= l && r <= qr) {
        tag[t] = val;
        pushdown (l, r, t);
        return ;
    }
    int mid = (l + r) >> 1;
    if (ql <= mid)
        modify (l, mid, ql, qr, val, t << 1);
    if (mid < qr)
        modify (mid + 1, r, ql, qr, val, t << 1 | 1);
    pushup (l, r, t);
}
ll query_max (int l, int r, int ql, int qr, int t) {
    pushdown (l, r, t);
    if (ql <= l && r <= qr) {
        return tr_max[t][0];
    }
    int mid = (l + r) >> 1;
    ll ret = -1;
    if (ql <= mid)
        ret = max (ret, query_max (l, mid, ql, qr, t << 1));
    if (mid < qr)
        ret = max (ret, query_max (mid + 1, r, ql, qr, t << 1 | 1));
    return ret;
}
ll query_sum (int l, int r, int ql, int qr, int t) {
    pushdown (l, r, t);
    if (ql <= l && r <= qr) {
        return tr_sum[t];
    }
    int mid = (l + r) >> 1;
    ll ret = 0;
    if (ql <= mid)
        ret += query_sum (l, mid, ql, qr, t << 1);
    if (mid < qr)
        ret += query_sum (mid + 1, r, ql, qr, t << 1 | 1);
    return ret;
}
void solve () {
    cin >> n >> q;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    build (1, n, 1);
    while (q --) {
        ll op, x, y, z;
        cin >> op;
        if (!op) {
            cin >> x >> y >> z;
            modify (1, n, x, y, z, 1);
        } else if (op == 1) {
            cin >> x >> y;
            ll mx = 0;
            mx = query_max (1, n, x, y, 1);
            cout << mx << "\n";
        } else {
            cin >> x >> y;
            ll sum = 0;
            sum = query_sum (1, n, x, y, 1);
            cout << sum << "\n";
        }
    }
}
int main () {
    init ();
    ios::sync_with_stdio (0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve ();
    }
    return 0;
}