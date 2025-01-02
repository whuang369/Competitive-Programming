#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 64;
void prt (ll x, ll y) {
    cout << x << " " << y << "\n";
    cout.flush();
}
ll cal (ll x) {
    ll ret = 0;
    while (x) {
        ret += (x & 1);
        x >>= 1;
    }
    return ret;
}
ll cal2 (ll x) {
    ll ret = x;
    for (int i = N - 1; i >= 0; i --)
        if (x & (1ll << i)) {
            ret ^= (1ll << i);
            break ;
        }
    return ret;
}
void solve () {
    ll n;
    cin >> n;
    if (cal (n) & 1) {
        cout << "second\n";
        cout.flush();
    } else {
        cout << "first\n";
        cout.flush();
        prt (cal2 (n), (n ^ cal2 (n)));
    }
    ll p1, p2;
    cin >> p1 >> p2;
    while (p1 != 0 || p2 != 0) {
        if (p1 == -1 && p2 == -1)
            exit(0);
        if (cal (p1) & 1)
            n = p2;
        else
            n = p1;
        prt (cal2 (n), (n ^ cal2 (n)));
        cin >> p1 >> p2;
    }
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