#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 45;
ll n, a[N], s[N];
vector <ll> lsum, rsum;
ll q (ll x) {
    ll l = 0, r = 0;
    ll ret = 0;
    while (r < rsum.size() - 1 && lsum[l] + rsum[r + 1] < x)
        r ++;
    for (l = 0; l < lsum.size(); l ++) {
        while (r >= 0 && lsum[l] + rsum[r] >= x)
            r --;
        if (r < 0)
            break ;
        ret += r + 1;
    }
    return ret;
}
ll qry (ll x, ll y) {
    return q(y + 1) - q(x);
}
void solve () {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    sort (a + 1, a + n + 1);
    for (int i = 1; i <= n; i ++)
        s[i] = s[i - 1] + a[i];
    ll len = n / 2;
    for (ll i = 0; i < (1 << len); i ++) {
        ll sum = 0;
        for (int j = 0; j < len; j ++)
            if (i & (1 << j))
                sum += a[j + 1];
        lsum.push_back(sum);
    }
    sort (lsum.begin(), lsum.end());
    ll len2 = n - len;
    for (ll i = 0; i < (1 << len2); i ++) {
        ll sum = 0;
        for (int j = 0; j < len2; j ++)
            if (i & (1 << j))
                sum += a[len + j + 1];
        rsum.push_back(sum);
    }
    sort (rsum.begin(), rsum.end());
    ll l = 1, r = s[n];
    while (l < r) {
        ll mid = (l + r) >> 1;
        if (qry (l, mid) > mid - l + 1)
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << "\n";
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        solve ();
    }
}