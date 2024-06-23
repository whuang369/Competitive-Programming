#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e5 + 5;
ll n, a[N];
void solve () {
    cin >> n;
    int smc = 1;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        if (a[i] != a[1])
            smc = 0;
    }
    if (smc) {
        cout << "-1\n";
        return ;
    }
    ll l = 0;
    ll mn = n;
    for (int i = 1; i <= n; i ++)
        if (a[i] != a[1]) {
            mn = min (mn, i - l - 1);
            l = i;
        }
    mn = min (mn, n + 1 - l - 1);
    cout << mn << "\n";
}
int main () {
    ios::sync_with_stdio (0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve ();
    }
    return 0;
}