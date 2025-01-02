#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s, t, mxs, mxt;
int n;
ll mx = -1;
ll res (string ss, string tt) {
    ll mul = 1;
    ll x = 0, y = 0;
    for (int i = 0; i < n; i ++) {
        x = x * 10 + (ll)(ss[i] - '0');
        y = y * 10 + (ll)(tt[i] - '0');
    }
    return x * y;
}
void solve () {
    cin >> s >> t;
    n = s.size ();
    // mx = -1;
    // for (int I = 0; I < (1 << n); I ++) {
    //     string ss = s, tt = t;
    //     for (int i = 0; i < n; i ++)
    //         if (I & (1 << i))
    //             swap (ss[i], tt[i]);
    //     ll rest = res (ss, tt);
    //     if (rest > mx) {
    //         mx = rest;
    //         mxs = ss;
    //         mxt = tt;
    //     }
    // }
    // cout << mxs << "\n" << mxt << "\n";
    int spd = 0;
    for (int i = 0; i < n; i ++) {
        if (s[i] != t[i]) {
            if (!spd) {
                if (s[i] < t[i])
                    swap (s[i], t[i]);
                spd = 1;
            } else {
                if (s[i] > t[i])
                    swap (s[i], t[i]);
            }
        }
    }
    cout << s << "\n" << t << "\n";
}
int main () {
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