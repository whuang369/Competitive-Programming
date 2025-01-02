#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e5 + 5;
ll n, q, a[N], s1[N], sum[N];
void solve () {
    cin >> n >> q;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        s1[i] = s1[i - 1];
        sum[i] = sum[i - 1];
        if (a[i] == 1)
            s1[i] ++;
        sum[i] += a[i] - 1;
    }
    while (q --) {
        int l, r;
        cin >> l >> r;
        if (l == r) {
            cout << "NO\n";
            continue;
        }
        ll s_1 = s1[r] - s1[l - 1];
        ll sum_1 = sum[r] - sum[l - 1];
        if (sum_1 >= s_1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
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