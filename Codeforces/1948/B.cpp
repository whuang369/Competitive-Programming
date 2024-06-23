#include <bits/stdc++.h>
#define ll long long
using namespace std;
string itos (int x) {
    if (x == 0)
        return "0";
    string ret = "";
    while (x) {
        ret = (char)(x % 10 + '0') + ret;
        x /= 10;
    }
    return ret;
}
void solve () {
    int n;
    cin >> n;
    int lst = -1, ok = 1;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        string cur = itos(x);
        if (lst <= (cur[0] - '0') && (cur.size() == 1 || (cur[0] - '0') <= (cur[1] - '0'))) {
            lst = cur[0] - '0';
            if (cur.size() != 1)
                lst = cur[1] - '0';
        } else {
            if (lst > x) {
                ok = 0;
            } else {
                lst = x;
            }
        }
    }
    if (ok)
        cout << "YES\n";
    else
        cout << "NO\n";
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
}