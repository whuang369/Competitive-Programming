#include <bits/stdc++.h>
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 2e5 + 5;
ll n, q, w[N], sum[N][30], wsum[N][30];
pair <ll, ll> p[N];
void solve () {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> p[i].F >> p[i].S;
        w[i] = 0;
        for (int j = 29; j >= 0; j --)
            if ((p[i].F & (1ll << j)) && p[i].S & (1ll << j))
                w[i] |= (1ll << j);
            else if (max (p[i].F, p[i].S) >= (1ll << j))
                break ;
        p[i].F -= w[i];
        p[i].S -= w[i];
        for (int j = 0; j < 30; j ++) {
            sum[i][j] = sum[i - 1][j];
            wsum[i][j] = wsum[i - 1][j];
            if (p[i].S & (1ll << j))
                sum[i][j] ++;
            if (w[i] & (1ll << j))
                wsum[i][j] ++;
        }
    }
    cin >> q;
    while (q --) {
        int l, r;
        cin >> l >> r;
        ll ans = 0;
        for (int i = 29; i >= 0; i --)
            if (wsum[r][i] - wsum[l - 1][i])
                ans |= (1ll << i);
        for (int i = 29; i >= 0; i --) {
            if (sum[r][i] - sum[l - 1][i] == 1)
                ans |= (1ll << i);
            // if (i == 1)
            //     cout << sum[r][i] - sum[l - 1][i] << " " << wsum[r][i] - wsum[l - 1][i] << "\n";
            if (sum[r][i] - sum[l - 1][i] > 1 || (sum[r][i] - sum[l - 1][i] == 1 && wsum[r][i] - wsum[l - 1][i] >= 1)) {
                ans |= (1ll << i);
                ans |= (1ll << i) - 1;
                break ;
            }
        }
        cout << ans << " ";
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