#include <bits/stdc++.h>
using namespace std;
int ab(int x) {
    return max (x, -x);
}
void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i ++)
        cin >> a[i];
    sort (a.begin(), a.end());
    int ans = 0;
    int i = 0, l = n - 1;
        for (int j = i + 1; j < n; j ++)
            for (int k = j + 1; k < l; k ++){
                    ans = max (ans, ab(a[i] - a[l]) + ab(a[j] - a[k]) + ab(a[i] - a[k]) + ab(a[j] - a[l]));
                }
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