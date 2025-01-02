#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
int n;
db mn;
db ab (db x) {
    return max (x, 0.0 - x);
}
void solve () {
    cin >> n;
    db mn = -1.0;
    for (int i = 1; i <= n; i ++) {
        db x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if ((x1 > 0 && x2 > 0) || (x1 < 0 && x2 < 0))
            continue ;
        if (y1 > y2) {
            swap (y1, y2);
            swap (x1, x2);
        }
        db dx1 = ab (x1), dx2 = ab (x2);
        db dy = (y2 - y1) / (dx1 + dx2) * dx1;
        db yy = dy + y1;
        if (yy > 0.0) {
            if (mn == -1.0)
                mn = yy;
            else
                mn = min (mn, yy);
        }
    }
    if (mn == -1.0) {
        cout << "-1.0\n";
    } else
        cout << fixed << setprecision(10) << mn << "\n";
}
int main () {
    ios::sync_with_stdio (0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        solve ();
    }
}