#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e5 + 5;
const ll MOD = 998244353;
int n, q;
void solve () {
    cin >> n >> q;
    vector <pair <int, int> > p(n + 1);
    vector <int> bef(n + 1), nxt(n + 1), exi(n + 1);
    vector <int> seq(q + 3), inc(n + 1);
    for (int i = 1; i <= q; i ++) {
        cin >> p[i].first;
    }
    for (int i = 1; i <= n; i ++)
        bef[i] = nxt[i] = -1;
    for (int i = 1; i <= q; i ++)
        cin >> p[i].second;
    int head = -1, end = -1;
    for (int i = 1; i <= q; i ++) {
        int l = p[i].first, r = p[i].second;
        if (i == 1) {
            head = l;
            end = r;
            nxt[l] = r;
            bef[r] = l;
        } else if (exi[l]) {
            int r2 = nxt[l];
            bef[r] = l;
            nxt[r] = r2;
            nxt[l] = r;
            if (r2 != -1)
                bef[r2] = r;
            else
                end = r;
        } else {
            int l2 = bef[r];
            bef[l] = l2;
            nxt[l] = r;
            bef[r] = l;
            if (l2 != -1)
                nxt[l2] = l;
            else
                head = l;
        }
        exi[l] = exi[r] = 1;
    }
    for (int i = 1, cur = head; i <= q + 1; i ++, cur = nxt[cur]) {
        seq[i] = cur;
    }
    for (int i = 1; i <= q + 2; i ++) {
        int mx = max (seq[i - 1], seq[i]);
        inc[mx] ++;
    }
    ll ans = 1, sum = 0;
    for (int i = n; i >= 1; i --) {
        sum += inc[i];
        if (!exi[i]) {
            // cout << i << ":" << sum << "\n";
            ans *= sum;
            ans %= MOD;
            sum ++;
        }
    }
    cout << ans << "\n";
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
}