#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
const int N = 1e5 + 5;
db x_1, y_1, x_2, y_2, a, x_0, y_0;
db b, c, d, ang;
db mxx, mxy, mnx, mny;
void solve () {
    cin >> x_1 >> y_1 >> x_2 >> y_2 >> a;
    a /= 2;
    x_0 = (x_1 + x_2) / 2;
    y_0 = (y_1 + y_2) / 2;
    double dx = x_2 - x_1;
    double dy = y_2 - y_1;
    c = sqrt (dx * dx + dy * dy) * 0.5;
    b = sqrt (a * a - c * c);
    ang = atan2 (y_2 - y_1, x_2 - x_1);
    double ca = cos (ang);
    double sa = sin (ang);
    double a_2 = a * ca;
    double b_2 = -b * sa;
    double DDx = sqrt (a_2 * a_2 + b_2 * b_2);
    double a_3 = a * sa;
    double b_3 = b * ca;
    double DDy = sqrt (a_3 * a_3 + b_3 * b_3);
    mxx = x_0 + DDx;
    mnx = x_0 - DDx;
    mxy = y_0 + DDy;
    mny = y_0 - DDy;
    cout << fixed << setprecision (10) << mnx << " " << mny << " " << mxx << " " << mxy << "\n";
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