#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll b, c, d;
void solve () {
    ll a = 0;
    cin >> b >> c >> d;
    ll ans = 0;
    for (ll i = 62; i >= 0; i --) {
        ll cur = (1ll << i);
        ll num[3] = {(cur & b) ? 1 : 0, (cur & c) ? 1 : 0, (cur & d) ? 1 : 0};
        ll typ = num[0] * 4 + num[1] * 2 + num[2];
        switch (typ) {
            case 0:
                ans = (ans << 1) + 0;
                break;
            case 1:
                ans = (ans << 1) + 1;
                break;
            case 2:
                ans = (ans << 1) + 0;
                break;
            case 3:
                cout << "-1\n";
                return ;
                break;
            case 4:
                cout << "-1\n";
                return ;
                break;
            case 5:
                ans = (ans << 1) + 0;
                break;
            case 6:
                ans = (ans << 1) + 1;
                break;
            case 7:
                ans = (ans << 1) + 0;
                break;
            
            default:
                break;
        }
    }
    cout << ans << "\n";
}
int main () {
    ios::sync_with_stdio (0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve ();
    }
}