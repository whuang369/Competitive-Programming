#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, k;
vector <ll> solve2 (int x) {
    ll now = 1, i, j;
    vector <ll> ret;
    for (i = 1, j = 0; i <= x; i *= 2, j ++);
    i >>= 1;
    ret.push_back(k - i);
    ret.push_back(k + 1);
    ret.push_back(k + i + 1);
    ll mx = i;
    for (i = 1, j = 0; j < 20; i *= 2, j ++)
        if (i != mx)
            ret.push_back(i);
    return ret;
}
void solve () {
    cin >> n >> k;
    vector <ll> ans = solve2 (k);
    cout << ans.size() << "\n";
    for (ll x : ans)
        cout << x << " ";
    cout << "\n";
}
int main () {
    int T;
    cin >> T;
    while (T --) {
        solve ();
    }
}