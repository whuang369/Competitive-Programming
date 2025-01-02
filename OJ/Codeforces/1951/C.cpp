#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, k;
void solve () {
    cin >> n >> m >> k;
    vector <ll> a(n);
    for (int i = 0; i < n; i ++)
        cin >> a[i];
    sort (a.begin(), a.end());
    ll ans = 0, lft = k, sum = k * k;
    for (int i = 0; i < n; i ++) {
        ll now = min (m, lft);
        ans += a[i] * now;
        sum -= now * now;
        lft -= now;
        if (lft == 0)
            break ;
    }
    sum /= 2;
    ans += sum;
    cout << ans << "\n";
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