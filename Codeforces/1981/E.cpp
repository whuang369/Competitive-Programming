#include <bits/stdc++.h>
#define L first
#define R second
#define val second
#define ll long long
using namespace std;
const int N = 5e5 + 5;
int n, fa[N];
int cnt = 0;
int find (int x) {
    return fa[x] == x ? x : fa[x] = find (fa[x]);
}
void merge (int x, int y) {
    int xx = find (x), yy = find (y);
    if (xx == yy)
        return ;
    fa[xx] = yy;
    return ;
}
ll ab (ll x) {
    return max (x, -x);
}
ll val[N];
bool cmp (pair <int, int> a, pair <int, int> b) {
    return ab (val[a.first] - val[a.second]) < ab (val[b.first] - val[b.second]);
}
void solve () {
    cin >> n;
    vector <pair <ll, ll> > p(n + 1);
    set <ll> pts;
    for (int i = 1; i <= n; i ++) {
        cin >> p[i].L >> p[i].R >> val[i];
        pts.insert (p[i].L);
        pts.insert (p[i].R);
    }
    cnt = 0;
    map <ll, int> mp;
    for (ll x : pts) {
        cnt ++;
        mp[x] = cnt;
    }
    vector <int> vl[cnt + 1], vr[cnt + 1];
    for (int i = 1; i <= n; i ++) {
        vl[mp[p[i].L]].push_back (i);
        vr[mp[p[i].R]].push_back (i);
    }
    for (int i = 1; i <= n; i ++)
        fa[i] = i;
    set <pair <ll, int> > cur_s;
    vector <pair <int, int> > egs;
    for (int pos = 1; pos <= cnt; pos ++) {
        for (int num : vl[pos])
            cur_s.insert (make_pair (val[num], num));
        for (int num : vl[pos]) {
            auto pt = cur_s.find(make_pair (val[num], num));
            int bef_num = 0, nxt_num = 0;
            if (pt != cur_s.begin()) {
                auto bpt = prev(pt);
                bef_num = (*bpt).second;
                merge (bef_num, num);
                egs.push_back (make_pair (bef_num, num));
            }
            pt ++;
            if (pt != cur_s.end()) {
                nxt_num = (*pt).second;
                merge (num, nxt_num);
                egs.push_back (make_pair (nxt_num, num));
            }
        }
        for (int num : vr[pos])
            cur_s.erase (make_pair (val[num], num));
    }
    for (int i = 2; i <= n; i ++)
        if (find (i) != find (1)) {
            cout << "-1\n";
            return ;
        }
    for (int i = 1; i <= n; i ++)
        fa[i] = i;
    ll ans = 0;
    sort (egs.begin(), egs.end(), cmp);
    for (auto i : egs) {
        int x = i.first, y = i.second;
        int xx = find (x), yy = find (y);
        if (xx == yy)
            continue ;
        ans += ab(val[x] - val[y]);
        fa[xx] = yy;
    }
    cout << ans << "\n";
}
int main () {
    ios::sync_with_stdio (false);
    cin.tie (0);
    cout.tie (0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve ();
    }
}