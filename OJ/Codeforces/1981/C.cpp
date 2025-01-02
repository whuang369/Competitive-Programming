#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int mxb (ll x) {
    for (int i = 31; i >= 0; i --)
        if (x & (1ll << i))
            return i;
}
void solve () {
    cin >> n;
    vector <ll> a(n + 2);
    a[n + 1] = 1;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    int l = 1;
    while (l <= n && a[l] == -1)
        l ++;
    for (int i = l - 1; i >= 1; i --) {
        if (a[i + 1] == 1)
            a[i] = 2;
        else
            a[i] = a[i + 1] / 2;
    }
    for (int i = l + 1; i <= n; i ++) {
        if (a[i] == -1)
            continue ;
        if (l == i - 1) {
            if ((ll)(a[i] / 2) != a[i - 1] && (ll)(a[i - 1] / 2) != a[i]) {
                cout << "-1\n";
                return ;
            }
            l = i;
            continue ;
        }
        ll dis = i - l;
        ll d = mxb(a[i]) - mxb(a[l]);
        ll mn = min (a[l], a[i]), mx = max (a[l], a[i]);
        if (d < 0) d = -d;
        if (dis % 2 != d % 2) {
            cout << "-1\n";
            return ;
        }
        ll temp = (mx >> d); int mnp = 0;
        for (int j = 31; j >= 0; j --)
            if ((mn & (1 << j)) == (temp & (1 << j)))
                mnp = j;
            else
                break ;
        if (dis < d + mnp * 2) {
            cout << "-1\n";
            return ;
        }
        int now = 0;
        vector <ll> tp;
        now ++;
        tp.push_back (mn);
        for (int j = 1; j <= mnp; j ++) {
            now ++;
            tp.push_back (mn >> j);
        }
        for (int j = mxb(mn) - mnp + 1; j <= mxb(mx); j ++) {
            now ++;
            tp.push_back (mx >> (mxb(mx) - j));
        }
        while (now < dis + 1) {
            now += 2;
            if (mx == 1)
                tp.push_back (mx << 1);
            else
                tp.push_back (mx >> 1);
            tp.push_back (mx);
        }
        if (a[i] == mn)
            reverse (tp.begin(), tp.end());
        for (int vj = 0, aj = l; vj < tp.size(); vj ++, aj ++) {
            a[aj] = tp[vj];
        }
        l = i;
    }
    if (l < n) {
        for (int i = l + 1; i <= n; i ++)
            if (a[i - 1] == 1)
                a[i] = 2;
            else
                a[i] = a[i - 1] / 2;
    }
    for (int i = 1; i <= n; i ++)
        cout << a[i] << " ";
    cout << "\n";
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