#include <bits/stdc++.h>
using namespace std;
void solve () {
    int n, m;
    cin >> n >> m;
    vector <int> a(101);
    int ok = 0;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        a[x] ++;
        if (a[x] >= m)
            ok = 1;
    }
    if (ok) {
        cout << min (n, m - 1) << "\n";
    } else
        cout << n << "\n";
}
int main () {
    int T;
    cin >> T;
    while (T --) {
        solve ();
    }
}