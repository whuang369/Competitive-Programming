#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 55;
int n, m, a[N];
void solve () {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    sort (a + 1, a + n + 1);
    m *= 5;
    int sum = 0;
    for (int i = 1; i <= n; i ++) {
        if (sum + a[i] > m) {
            cout << i - 1 << "\n";
            return ;
        }
        if (i == n) {
            cout << n << "\n";
            return ;
        }
        sum += a[i];
    }
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