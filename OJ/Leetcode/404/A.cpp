#include <bits/stdc++.h>
using namespace std;
void solve () {
    int red; int blue;
    cin >> red >> blue;
    int mx = 0;
    for (int i = 1; i <= red; i ++) {
        if (i * i <= red && i * (i + 1) <= blue)
            mx = i;
        else
            break ;
    }
    if ((mx + 1) * (mx + 1) <= red)
        mx = mx * 2 + 1;
    else
        mx *= 2;
    int mx2 = 0;
    for (int i = 1; i <= blue; i ++) {
        if (i * i <= blue && i * (i + 1) <= red)
            mx2 = i;
        else
            break ;
    }
    if ((mx2 + 1) * (mx2 + 1) <= blue)
        mx2 = mx2 * 2 + 1;
    else
        mx2 *= 2;
    mx = max (mx, mx2);
    cout << mx << "\n";
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve();
    }
}