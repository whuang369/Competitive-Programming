#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve () {
    ll n, k;
    ll kk = 0;
    cin >> n >> k;
    kk = k;
    if (k > (ll)(n * n / 2) || k % 2) {
        cout << "No\n";
        return ;
    }
    vector <ll> p(n + 1);
    ll lst = n;
    for (int i = 1; i <= n; i ++) {
        if (p[i])
            continue ;
        if (!k) {
            p[i] = i;
            continue ;
        }
        if (k >= (lst - i) * 2) {
            p[i] = lst;
            p[lst] = i;
            k -= (lst - i) * 2;
            lst --;
            continue ;
        } else {
            lst = k / 2 + i;
            p[i] = lst;
            p[lst] = i;
            k -= (lst - i) * 2;
            continue ;
        }
    }
    cout << "Yes\n";
    // ll sum = 0;
    for (int i = 1; i <= n; i ++) {
        cout << p[i] << " ";
        // sum += max (p[i] - i, i - p[i]);
    }
    cout << "\n";
    // if (sum != kk)
    //     cout << "FFfffffffffff\n";
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