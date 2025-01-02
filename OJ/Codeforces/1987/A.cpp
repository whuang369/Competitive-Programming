#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve () {
    ll n, k;
    cin >> n >> k;
    cout << (n - 1) * k + 1 << "\n";
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