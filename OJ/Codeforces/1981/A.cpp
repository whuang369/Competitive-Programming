#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int n;
void solve () {
    ll l, r;
    cin >> l >> r;
    for (int i = 31; i >= 0; i --)
        if ((1ll << i) <= r) {
            cout << i << "\n";
            return ;
        }
}
int main () {
    ios::sync_with_stdio (0);
    cin.tie (0);
    cout.tie (0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve ();
    }
}