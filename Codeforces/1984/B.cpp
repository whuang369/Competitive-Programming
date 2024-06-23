#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll sto (string s) {
    ll ret = 0;
    for (int i = 0; i < s.size(); i ++)
        ret = ret * 10 + s[i] - '0';
    return ret;
}
void solve () {
    string s;
    cin >> s;
    ll num = sto (s);
    ll te = 1, mn = 0, mx = 0, cnt = 0;
    for (int i = 1; i < s.size(); i ++) {
        te *= 10ll;
        mn += te;
    }
    if (num < mn || num > te * 2ll - 2ll || s[s.size() - 1] == '9')
        cout << "NO\n";
    else {
        for (int i = 0; i < s.size() - 1; i ++)
            if (s[i] == '0') {
                cout << "NO\n";
                return ;
            }
        cout << "YES\n";
    }
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