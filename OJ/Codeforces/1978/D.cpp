#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
ll n, c, a[N], ans[N];
void solve () {
    cin >> n >> c;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    a[1] += c;
    ll mx = -1, mxnum = 0;
    for (int i = 1; i <= n; i ++) {
        if (mx < a[i]) {
            mx = a[i];
            mxnum = i;
        }
    }
    ans[mxnum] = 0;
    for (int i = mxnum + 1; i <= n; i ++)
        ans[i] = i - 1;
    ll sum = 0;
    for (int i = 1; i < mxnum; i ++) {
        sum += a[i];
        if (sum < mx)
            ans[i] = i;
        else
            ans[i] = i - 1;
    }
    for (int i = 1; i <= n; i ++)
        cout << ans[i] << " ";
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
}