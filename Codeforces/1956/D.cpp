#include <bits/stdc++.h>
using namespace std;
const int N = 19;
int n, a[N];
vector <pair <int, int> > ops;
int mex (int l, int r) {
    set <int> s;
    for (int i = l; i <= r; i ++)
        s.insert (a[i]);
    int cnt = 0;
    for (int x : s) {
        if (x != cnt)
            return cnt;
        cnt ++;
    }
    return cnt;
}
void op (int l, int r, int t) {
    if (t)
        ops.push_back (make_pair (l, r));
    int val = mex (l, r);
    for (int i = l; i <= r; i ++)
        a[i] = val;
    return ;
}
void opt (int l, int r, int t) {
    if (l == r) {
        if (a[l] != 0)
            op (l, r, t);
        return ;
    }
    opt (l, r - 1, t);
    if (a[r] != 0)
        op (r, r, t);
    op (l, r, t);
    opt (l, r - 1, t);
    return ;
}
void solve () {
    cin >> n;
    vector <int> ori (n + 1);
    for (int i = 1; i <= n; i ++)
        cin >> ori[i];
    // for (int j = 1; j <= n; j ++)
    //     a[j] = ori[j];
    // opt (1, n, 0);
    // for (int i = 1; i <= n; i ++)
    //     cout << a[i] << " ";
    // cout << "\n";
    int mx = -1, mxn;
    for (int I = 0; I < (1 << n); I ++) {
        int l = 1;
        for (int j = 1; j <= n; j ++)
            a[j] = ori[j];
        for (int j = 1; j <= n; j ++)
            if (I & (1 << (j - 1))) {
                if (l == j) {
                    l ++;
                    continue ;
                }
                for (int k = l; k < j; k ++)
                    a[k] = j - l;
                l = j + 1;
            }
        if (l != n + 1) {
            for (int k = l; k <= n; k ++)
                a[k] = n - l + 1;
        }
        int sum = 0;
        for (int j = 1; j <= n; j ++)
            sum += a[j];
        if (mx < sum) {
            mx = sum;
            mxn = I;
        }
    }
    int l = 1;
    for (int j = 1; j <= n; j ++)
        a[j] = ori[j];
    ops.clear ();
    for (int j = 1; j <= n; j ++)
        if (mxn & (1 << (j - 1))) {
            if (l == j) {
                l ++;
                continue ;
            }
            opt (l, j - 1, 1);
            op (l, j - 1, 1);
            l = j + 1;
        }
    if (l != n + 1) {
        opt (l, n, 1);
        op (l, n, 1);
    }
    cout << mx << " " << ops.size () << "\n";
    for (auto x : ops) {
        cout << x.first << " " << x.second << "\n";
    }
    return ;
}
int main () {
    ios::sync_with_stdio (0);
    cin.tie (0);
    cout.tie (0);
    int T = 1;
    // cin >> T;
    while (T --) {
        solve ();
    }
    return 0;
}