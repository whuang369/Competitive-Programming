#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve () {
    ll x1, y1;
    ll x2, y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    if (x1 > y1 && x2 > y2)
        cout << "YES\n";
    else if (x1 < y1 && x2 < y2)
        cout << "YES\n";
    else
        cout << "NO\n";
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