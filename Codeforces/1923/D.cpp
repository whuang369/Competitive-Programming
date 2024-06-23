#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e5 + 5;
ll n, a[N], sum[N], lans[N], rans[N], ls[N], rs[N];
void solve () {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    rs[n] = n;
    for (int i = n - 1; i >= 1; i --)
        if (a[i] == a[i + 1])
            rs[i] = rs[i + 1];
        else
            rs[i] = i;
    ls[1] = 1;
    for (int i = 2; i <= n; i ++)
        if (a[i] == a[i - 1])
            ls[i] = ls[i - 1];
        else
            ls[i] = i;
    for (int i = 1; i <= n; i ++) {
        int l = i + 1, r = n, cur = -1;
        if (i == n || sum[r] - sum[i] <= a[i]) {
            rans[i] = -1;
            continue;
        }
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (sum[mid] - sum[i] <= a[i])
                l = mid + 1;
            else {
                cur = mid;
                r = mid - 1;
            }
        }
        if (cur > i + 1)
            rans[i] = max ((ll)cur, rs[i + 1] + 1);
        else
            rans[i] = cur;
        if (rans[i] > n) {
            rans[i] = -1;
            continue ;
        }
        rans[i] = rans[i] - i;
    }
    for (int i = 1; i <= n; i ++) {
        int l = 1, r = i - 1, cur = -1;
        if (i == 1 || sum[i - 1] <= a[i]) {
            lans[i] = -1;
            continue;
        }
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (sum[i - 1] - sum[mid - 1] <= a[i])
                r = mid - 1;
            else {
                cur = mid;
                l = mid + 1;
            }
        }
        if (cur < i - 1)
            lans[i] = min ((ll)cur, ls[i - 1] - 1);
        else
            lans[i] = cur;
        if (lans[i] < 1) {
            lans[i] = -1;
            continue ;
        }
        lans[i] = i - lans[i];
    }
    for (int i = 1; i <= n; i ++) {
        if (lans[i] == -1 && rans[i] == -1)
            cout << "-1 ";
        else if (lans[i] == -1)
            cout << rans[i] << " ";
        else if (rans[i] == -1)
            cout << lans[i] << " ";
        else
            cout << min (lans[i], rans[i]) << " ";
    }
    cout << "\n";
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