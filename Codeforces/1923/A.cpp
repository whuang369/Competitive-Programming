#include <bits/stdc++.h>
using namespace std;
void solve () {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i ++)
        cin >> a[i];
    int l = -1, r = -1, sum = 0;
    for (int i = 0; i < n; i ++)
        if (a[i] == 1) {
            if (l == -1)
                l = i;
            r = i;
            sum ++;
        }
    cout << (r - l + 1) - sum << "\n";
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
    return 0;
}