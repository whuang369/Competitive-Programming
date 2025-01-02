#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve () {
    ll n, a, b;
    cin >> n >> a >> b;
    if (b <= a) {
        cout << n * a << "\n";
        return ;
    }
    ll len = (b - a + 1);
    if (len >= n) {
        ll fi = b, se = b - n + 1;
        cout << (fi + se) * n / 2 << "\n";
        return ;
    }
    ll fi = b, se = a;
    cout << (fi + se) * len / 2 + (n - len) * a << "\n";
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