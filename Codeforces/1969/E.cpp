#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e5 + 5;
int n, ans, a[N], pre[N], tr[N << 2], tag[N << 2];
void pushdown (int l, int r, int t) ;
void pushup (int l, int r, int t) {
    if (l != r) {
        // int mid = (l + r) >> 1;
        pushdown (l, r, t);
        tr[t] = min (tr[t << 1], tr[t << 1 | 1]);
    }
    return ;
}
void pushdown (int l, int r, int t) {
    if (l != r) {
        tr[t << 1] += tag[t];
        tag[t << 1] += tag[t];
        tr[t << 1 | 1] += tag[t];
        tag[t << 1 | 1] += tag[t];
    }
    tag[t] = 0;
    return ;
}
void build (int l, int r, int t) {
    tr[t] = 0;
    tag[t] = 0;
    if (l == r)
        return ;
    int mid = (l + r) >> 1;
    build (l, mid, t << 1);
    build (mid + 1, r, t << 1 | 1);
    return ;
}
void upd (int l, int r, int ql, int qr, int val, int t) {
    if (ql > qr)
        return ;
    if (ql <= l && r <= qr) {
        tr[t] += val;
        tag[t] += val;
        pushdown (l, r, t);
        return ;
    }
    int mid = (l + r) >> 1;
    if (ql <= mid)
        upd (l, mid, ql, qr, val, t << 1);
    if (mid < qr)
        upd (mid + 1, r, ql, qr, val, t << 1 | 1);
    pushup (l, r, t);
    return ;
}
int query (int l, int r, int ql, int qr, int t) {
    pushdown (l, r, t);
    if (ql <= l && r <= qr) {
        return tr[t];
    }
    int mid = (l + r) >> 1, ret = N * 4;
    if (ql <= mid)
        ret = min (ret, query (l, mid, ql, qr, t << 1));
    if (mid < qr)
        ret = min (ret, query (mid + 1, r, ql, qr, t << 1 | 1));
    pushup (l, r, t);
    return ret;
}
void solve () {
    cin >> n;
    build (1, n, 1);
    vector <int> pos[n + 1];
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    int lst = 0;
    ans = 0;
    for (int i = 1; i <= n; i ++) {
        int x = a[i];
        pos[x].push_back (i);
        int siz = pos[x].size ();
        if (siz > 0)
            upd (1, n, lst + 1, pos[x][siz - 1], 1, 1);
        if (siz > 1)
            upd (1, n, lst + 1, pos[x][siz - 2], -2, 1);
        if (siz > 2)
            upd (1, n, lst + 1, pos[x][siz - 3], 1, 1);
        if (query (1, n, lst + 1, i, 1) == 0) {
            ans ++;
            lst = i;
        }
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
    return 0;
}