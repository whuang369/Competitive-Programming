#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd (ll x, ll y) {
    return y ? gcd (y, x % y) : x;
}
ll lca (ll x, ll y) {
    return x / gcd (x, y) * y;
}
void solve () {
    ll n;
    cin >> n;
    vector <ll> a(n), ans(n);
    ll mul = 1, sum1 = 0;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        mul = lca (mul, a[i]);
        sum1 += a[i];
    }
    ll sum = 0;
    for (int i = 0; i < n; i ++) {
        ans[i] = mul / a[i];
        sum += ans[i];
    }
    if (sum < mul) {
        for (ll x : ans)
            cout << x << " ";
        cout << "\n";
    } else {
        cout << "-1\n";
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