#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
void solve () {
    cin >> n;
    vector <int> a(n);
    int mx = -1;
    for (int i = 0; i < n; i ++)
        cin >> a[i];
    mx = max (a[0], a[1]);
    for (int i = 2; i < n; i ++)
        mx = min (mx, max (a[i - 1], a[i]));
    cout << mx - 1 << "\n";
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