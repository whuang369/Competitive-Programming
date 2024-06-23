#include <bits/stdc++.h>
#define F first
#define S second
#define mk make_pair
#define ll long long
using namespace std;
void solve () {
    int n;
    cin >> n;
    ll sum = 0;
    for (ll i = 1; i <= n; i ++)
        if (n % i)
            sum += n;
    cout << sum << "\n";
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