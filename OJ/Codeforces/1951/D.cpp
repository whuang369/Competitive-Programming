#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, k;
void solve () {
    cin >> n >> k;
    if (n < k || (n > k && n < 2 * k - 1)) {
        cout << "NO\n";
        return ;
    }
    cout << "YES\n";
    if (n % k == 0)
        cout << "1\n" << n / k << "\n";
    else
        cout << "2\n" << n - (k - 1) << " " << 1 << "\n";
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