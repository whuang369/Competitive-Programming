#include <bits/stdc++.h>
using namespace std;
int p1, p2, p3;
void solve () {
    cin >> p1 >> p2 >> p3;
    if ((p1 + p2 + p3) % 2 != 0) {
        cout << "-1\n";
        return ;
    }
    cout << min ((p1 + p2 + p3) / 2, p1 + p2) << "\n";
}
int main () {
    ios::sync_with_stdio (false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve ();
    }
    return 0;
}