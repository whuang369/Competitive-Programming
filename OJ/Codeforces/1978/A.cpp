#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve () {
    int n;
    cin >> n;
    ll ans = 0;
    vector <int> a(n - 1);
    for (int i = 0; i < n - 1; i ++)
        cin >> a[i];
    sort (a.begin(), a.end());
    cin >> ans;
    cout << ans + a[n - 2] << "\n";
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