#include <bits/stdc++.h>
using namespace std;
void solve () {
    int n, k;
    cin >> n >> k;
    int lft = n - 1;
    int ech = k - 1;
    int ans = (lft + ech - 1) / ech;
    cout << ans << "\n";
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