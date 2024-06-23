#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e5 + 5;
int n;
ll k, a[N], b[N], sum[N];
ll ab (ll x) {
    return max (x, -x);
}
void solve () {
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], sum[i] = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> b[i];
        sum[ab(b[i])] += a[i];
    }
    for (int i = 1; i <= n; i ++) {
        sum[i] += sum[i - 1];
        if (sum[i] > k * i) {
            cout << "NO\n";
            return ;
        }
    }
    cout << "YES\n";
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