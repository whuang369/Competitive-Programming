#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 55;
int n, l[N], r[N], dp[N];
bool check (int x) {
    if (l[x] <= x - 2 && r[x - 2] >= x)
        return true;
    return false;
}
void solve () {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> l[i] >> r[i];
    for (int i = 1; i <= n; i ++)
        if (check (i))
            dp[i] = max (dp[i - 1], dp[i - 3] + 1);
        else
            dp[i] = dp[i - 1];
    cout << dp[n] << "\n";
}
int main () {
    ios::sync_with_stdio (0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        solve ();
    }
}