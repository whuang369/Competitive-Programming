#include <bits/stdc++.h>
using namespace std;
int n, mx, mxindex, mnindex;
int query (int a, int b, int c, int d) {
    cout << "?  " << a << " " << b << " " << c << " " << d << "\n";
    cout.flush();
    string s;
    cin >> s;
    if (s == "=")
        return 0;
    if (s == "<")
        return -1;
    return 1;
}
void solve () {
    cin >> n;
    for (int i = 0; (1 << i) < n; i ++)
        mx = (1 << (i + 1)) - 1;
    mxindex = 0;
    for (int i = 1; i < n; i ++) {
        if (query (mxindex, mxindex, i, i) == -1)
            mxindex = i;
    }
    mnindex = 0;
    for (int i = 1; i < n; i ++) {
        int ret = query (mxindex, mnindex, mxindex, i);
        if (ret == -1)
            mnindex = i;
        else if (ret == 0) {
            if (query (mnindex, mnindex, i, i) == 1)
                mnindex = i;
        }
    }
    cout << "! " << mxindex << " " << mnindex << "\n";
    cout.flush();
    return ;
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