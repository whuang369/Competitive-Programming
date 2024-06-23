#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
string s;
int d[N], tr[N << 2], lb[N], rb[N], bsum[N], vpos[N], dnum[N];
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
        lb[i] = lb[i - 1] + (s[i] == '(' ? 1 : 0);
        rb[i] = rb[i - 1] + (s[i] == ')' ? 1 : 0);
    }
    vector <int> mp[N];
    map <int, int> mpnum;
    int cnt = 0;
    for (int i = n; i >= 1; i --) {
        if (!mpnum[d[i]]) {
            mpnum[d[i]] = ++ cnt;
        }
        dnum[i] = mpnum[d[i]];
        bsum[i] = mp[dnum[i]].size();
        mp[dnum[i]].push_back(i);
        vpos[i] = mp[dnum[i]].size() - 1;
    }
    build (1, n, 1);
    ll ans = 0;
    for (int i = 1; i <= n; i ++) {
        int l = i + 1, r = n;
        int oans = ans;
        if (query (1, n, l, r, 1) <= 2 * d[i]) {
            ans += bsum[i];
        } else {
            int pos = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (query (1, n, i + 1, mid, 1) > 2 * d[i]) {
                    r = mid - 1;
                } else {
                    pos = mid;
                    l = mid + 1;
                }
            }
            if (pos == -1)
                continue ;
            int l2 = i + 1, r2 = pos;
            l = vpos[i] + 1, r = mp[dnum[i]].size() - 1;
            int ca = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                int cur = mp[dnum[i]][mid];
                if (cur <= pos) {
                    ca = mid;
                    r = mid - 1;
                } else
                    l = mid + 1;
            }
            if (ca == -1)
                continue ;
            pos = mp[dnum[i]][ca];
            ans += vpos[i] - vpos[pos];
        }
    }
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