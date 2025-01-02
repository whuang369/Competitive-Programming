#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, k, lstl, lstr, pos, tims, lsa[2];
bool ol = true;
int que (ll l, ll r) {
    cout << "? " << l << " " << r << "\n";
    cout.flush();
    if (ol) {
        int x;
        cin >> x;
        return x;
    } else {
        tims ++;
        int ret = 0;
        if (l <= pos && pos <= r)
            ret = 1;
        if (r - l + 1 >= k)
            ret = 1 - ret;
        return ret;
    }
}
ll fnd () {
    ll pos[4] = {que (1, n / 4), que (n / 4 + 1, n / 2), que (n / 2 + 1, n - n / 4), 0};
    ll sum = pos[0] + pos[1] + pos[2];
    if (sum > 1)
        pos[3] = 3 - sum;
    else
        pos[3] = 1 - sum;
    if (sum > 1) {
        for (int i = 0; i < 4; i ++) {
            if (pos[i] == 0)
                continue ;
            ll ql = (n / 4) * i + 1, qr = (n / 4) * (i + 1);
            ll l = 2, r = n / 4, ans = 2;
            while (l <= r) {
                ll mid = (l + r) >> 1;
                if (que (ql, ql + mid - 1) == 1) {
                    ans = mid;
                    r = mid - 1;
                } else
                    l = mid + 1;
            }
            return ans;
        }
    } else {
        for (int i = 0; i < 4; i ++) {
            if (pos[i] == 0)
                continue ;
            ll ql = (n / 4) * i + 1, qr = (n / 4) * (i + 1);
            ll l = 1, r = n - n / 4, ans = n - n / 4;
            while (l <= r) {
                ll mid = (l + r) >> 1;
                ll nl = ql, nr = qr;
                if (qr + mid > n) {
                    nr = n;
                    nl = ql - (qr + mid - n);
                } else {
                    nr = qr + mid;
                }
                if (que (nl, nr) == 0) {
                    ans = mid;
                    r = mid - 1;
                } else
                    l = mid + 1;
            }
            return n / 4 + ans;
        }
    }
}
void solve () {
    if (ol) {
        cin >> n;
        ll ans = fnd ();
        cout << "! " << ans << "\n";
        cout.flush();
    } else {
        n = (1ll << 30);
        int T = 1;
        ll mx = -1;
        while (T --) {
            k = (ll)rand() * rand() % n + 1;
            if (k == 1) k ++;
            pos = (ll)rand() * rand() % n + 1;
            n = 16, k = 4, pos = 1;
            tims = 0;
            ll ans = fnd ();
            if (ans != k) {
                cout << "WRONG!\n";
                cout << k << " " << pos << "\n";
                cout << ans << "\n";
                return ;
            } else {
                cout << tims << "\n";
                mx = max (mx, tims);
            }
        }
        cout << mx << "\n";
    }
}
int main () {
    int T = 1;
    cin >> T;
    while (T --) {
        solve ();
    }
}