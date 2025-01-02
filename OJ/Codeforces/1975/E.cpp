#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int n, Q, tot, a[N], col[N], tr[N << 2];
int fas[N][20];
int fa[N], dep[N], dep_cnt[N], siz[N], hson[N];
int tp[N], dfn[N], rk[N], cnt;
int b_son[N], w_son;
set <pair <int, int> > pts;
vector <int> v[N];
void dfs (int x) {
    siz[x] = 1;
    hson[x] = 0;
    fas[x][0] = fa[x];
    for (int i = 1; i < 20; i ++)
        fas[x][i] = fas[fas[x][i - 1]][i - 1];
    for (int y : v[x]) {
        if (y == fa[x])
            continue ;
        fa[y] = x;
        dep[y] = dep[x] + 1;
        dfs (y);
        if (hson[x] == 0 || siz[hson[x]] < siz[y])
            hson[x] = y;
        siz[x] += siz[y];
    }
}
void dfs2 (int x, int top) {
    cnt ++;
    dfn[x] = cnt;
    rk[cnt] = x;
    tp[x] = top;
    if (!hson[x])
        return ;
    dfs2 (hson[x], top);
    for (int y : v[x]) {
        if (y == fa[x])
            continue ;
        if (y == hson[x])
            continue;
        dfs2 (y, y);
    }
}
void build (int l, int r, int t) {
    tr[t] = 0;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build (l, mid, t << 1);
    build (mid + 1, r, t << 1 | 1);
    return ;
}
void upd (int l, int r, int pos, int val, int t) {
    if (l == r) {
        tr[t] = val;
        return ;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        upd (l, mid, pos, val, t << 1);
    else
        upd (mid + 1, r, pos, val, t << 1 | 1);
    tr[t] = tr[t << 1] + tr[t << 1 | 1];
    return ;
}
int query (int l, int r, int ql, int qr, int t) {
    if (ql <= l && r <= qr) {
        return tr[t];
    }
    int mid = (l + r) >> 1, ret = 0;
    if (ql <= mid)
        ret += query (l, mid, ql, qr, t << 1);
    if (mid < qr)
        ret += query (mid + 1, r, ql, qr, t << 1 | 1);
    return ret;
}
int getfa (int x, int len) {
    int lft = len, now = x, i = 19;
    while (lft > 0) {
        if ((1 << i) <= lft) {
            now = fas[now][i];
            lft -= (1 << i);
        }
        i --;
    }
    return now;
}
int lca (int x, int y) {
    if (dep[x] < dep[y])
        swap (x, y);
    x = getfa (x, dep[x] - dep[y]);
    if (x == y)
        return x;
    int l = 1, r = dep[x] - 1, ans = dep[x];
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (getfa(x, mid) == getfa(y, mid)) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    return getfa (x, ans);
}
int cnt_road (int low, int high) {
    int ret = 0;
    if (dep[tp[low]] > dep[high]) {
        ret += query (1, n, dfn[tp[low]], dfn[low], 1);
        ret += cnt_road (fa[tp[low]], high);
    } else {
        ret += query (1, n, dfn[high], dfn[low], 1);
    }
    return ret;
}
void solve () {
    cin >> n >> Q;
    tot = 0;
    build (1, n, 1);
    w_son = 0;
    pts.clear();
    set <int> wson;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        for (int j = 0; j < 20; j ++)
            fas[i][j] = 0;
        fa[i] = dep[i] = dep_cnt[i] = siz[i] = hson[i] = tp[i] = dfn[i] = rk[i] = col[i] = b_son[i] = cnt = 0;
        v[i].clear ();
    }
    for (int i = 1; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back (y);
        v[y].push_back (x);
    }
    dep[1] = 1;
    dfs (1);
    dfs2 (1, 1);
    for (int i = 1; i <= n; i ++) {
        col[i] = a[i];
        if (col[i]) {
            tot ++;
            upd (1, n, dfn[i], col[i], 1);
            pts.insert (make_pair (dep[i], i));
            if (b_son[i] == 0) {
                w_son ++;
                wson.insert (i);
            }
            int f = fa[i];
            if (f == 0)
                continue ;
            b_son[f] ++;
            if (b_son[f] == 1 && col[f]) {
                w_son --;
                wson.erase(f);
            }
        }
    }
    while (Q --) {
        int x;
        cin >> x;
        // cout << "Question: " << x << "\n";
        col[x] ^= 1;
        if (col[x])
            tot ++;
        else
            tot --;
        upd (1, n, dfn[x], col[x], 1);
        if (col[x]) {
            pts.insert (make_pair (dep[x], x));
            if (b_son[x] == 0) {
                w_son ++;
                wson.insert (x);
            }
            int f = fa[x];
            if (f != 0) {
                b_son[f] ++;
                if (b_son[f] == 1 && col[f]) {
                    w_son --;
                    wson.erase(f);
                }
            }
        } else {
            pts.erase (make_pair (dep[x], x));
            if (b_son[x] == 0) {
                w_son --;
                wson.erase (x);
            }
            int f = fa[x];
            if (f != 0) {
                b_son[f] --;
                if (b_son[f] == 0 && col[f]) {
                    w_son ++;
                    wson.insert(f);
                }
            }
        }
        int rt = (*pts.begin()).second;
        if (w_son > 2 || w_son == 0)
            cout << "No\n";
        else if (w_son == 1) {
            vector <int> ps;
            for (int x : wson) {
                ps.push_back (x);
            }
            if (lca (ps[0], rt) != rt)
                cout << "No\n";
            else if (dep[ps[0]] - dep[rt] + 1 != tot || cnt_road(ps[0], rt) != tot)
                cout << "No\n";
            else
                cout << "Yes\n";
        } else {
            vector <int> ps;
            for (int x : wson) {
                ps.push_back (x);
            }
            int len = (dep[ps[0]] - dep[rt] + 1) + (dep[ps[1]] - dep[rt] + 1) - 1;
            if (lca (ps[0], ps[1]) != rt)
                cout << "No\n";
            else if (len != tot || cnt_road(ps[0], rt) + cnt_road(ps[1], rt) - 1 != tot)
                cout << "No\n";
            else
                cout << "Yes\n";
        }
    }
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