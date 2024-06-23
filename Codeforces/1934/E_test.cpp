#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 105;
ll ls[N];
ll cal (ll x) {
    ll ret = 0;
    while (x) {
        ret += x & 1;
        x >>= 1;
    }
    return ret;
}
void prt (ll x) {
    string s = "";
    while (x) {
        if (x & 1)
            s = "1" + s;
        else
            s = "0" + s;
        x >>= 1;
    }
    cout << s << "\n";
}
void solve () {
    ll n = 100;
    for (ll i = 1; i <= n; i ++)
        if (cal (i) == 1) {
            ls[i] = -1;
        } else {
            for (ll j = 1; j <= i; j ++) {
                ll p1 = j, p2 = i ^ j;
                if (p2 > i)
                    continue;
                if (ls[p1] == -1 && ls[p2] == -1) {
                    ls[i] = 1;
                    break ;
                }
            }
            if (!ls[i])
                ls[i] = -1;
        }
    cout << "===================\nwin:\n";
    for (int i = 1; i <= n; i ++)
        if (ls[i] == 1)
            prt (i);
    cout << "===================\nlose:\n";
    for (int i = 1; i <= n; i ++)
        if (ls[i] == -1)
            prt (i);
    return ;
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        solve ();
    }
}