#include <bits/stdc++.h>
using namespace std;
int h, m, tot;
string s;
string itos (int t) {
    string ret;
    int now = t;
    while (now) {
        ret = (char)(now % 10 + '0') + ret;
        now /= 10;
    }
    while (ret.size() < 2)
        ret = '0' + ret;
    return ret;
}
void solve() {
    cin >> s;
    cin >> tot;
    h = (s[0] - '0') * 10 + s[1] - '0';
    m = (s[3] - '0') * 10 + s[4] - '0';
    if (m <= 0)
        m = 0;
    else if (m <= 15)
        m = 15;
    else if (m <= 30)
        m = 30;
    else if (m <= 45)
        m = 45;
    else
        h ++, m = 0;
    int cur = 0;
    if (m == 0)
        cur += h;
    else
        cur ++;
    if (cur >= tot) {
        cout << itos (h) + ":" + itos (m) << "\n";
        return ;
    }
    while (cur < tot) {
        if (m == 0)
            m = 15;
        else if (m == 15)
            m = 30;
        else if (m == 30)
            m = 45;
        else if (m == 45)
            h ++, m = 0;
        if (h > 12)
            h = 1;
        if (m == 0)
            cur += h;
        else
            cur ++;
        if (cur >= tot) {
            cout << itos (h) + ":" + itos (m) << "\n";
            return ;
        }
    }
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