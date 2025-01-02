#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve () {
    ll n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << n << "\n";
        return ;
    }
    ll sum = 0;
    while (n) {
        sum += n % k;
        n /= k;
    }
    cout << sum << "\n";
}
int main () {
    ios::sync_with_stdio (0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve ();
    }
}