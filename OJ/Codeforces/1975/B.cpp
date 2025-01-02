#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
ll n, a[N];
void solve () {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    sort (a + 1, a + n + 1);
    ll x = a[1], mn = -1;
    vector <ll> v;
    for (int i = 2; i <= n; i ++)
        if (a[i] % x != 0) {
            if (mn == -1)
                mn = a[i];
            v.push_back (a[i]);
        }
    if (mn == -1 ) {
        cout << "Yes\n";
        return ;
    }
    for (int y : v) {
        if (y % mn != 0) {
            cout << "No\n";
            return ;
        }
    }
    cout << "Yes\n";
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