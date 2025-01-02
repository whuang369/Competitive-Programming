#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
void solve () {
    cin >> n;
    vector <int> a(n), b(n), mach(n + 1), pos (n + 1);
    vector <int> cur, lft;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        b[i] = a[i];
        pos[b[i]] = i;
    }
    int i1 = 0, i2 = 0;
    for (int i = 0; i < n; i ++)
        if (i % 2 != 1)
            cur.push_back (b[i]);
        else
            lft.push_back (b[i]);
    sort (cur.begin (), cur.end ());
    sort (lft.begin (), lft.end ());
    if (cur[cur.size() - 1] < lft[lft.size() - 1]) {
        cur.clear ();
        lft.clear ();
        for (int i = 0; i < n; i ++)
            if (i % 2 == 1)
                cur.push_back (b[i]);
            else
                lft.push_back (a[i]);
        sort (cur.begin (), cur.end ());
        sort (lft.begin (), lft.end ());
    }
    for (int i = 0; i < cur.size(); i ++)
        mach[cur[i]] = n - i;
    for (int i = 0; i < lft.size(); i ++)
        mach[lft[i]] = n / 2 - i;
    for (int i = 0; i < n; i ++)
        cout << mach[b[i]] << " ";
    cout << "\n";
    // int cnt = 0;
    // for (int i = 1; i < n - 1; i ++) {
    //     int l = b[i - 1] + mach[b[i - 1]], mid = b[i] + mach[b[i]], r = b[i + 1] + mach[b[i + 1]];
    //     if (l < mid && mid > r)
    //         cnt ++;
    // }
    // cout << cnt << "\n";
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