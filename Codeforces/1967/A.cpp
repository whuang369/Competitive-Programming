#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
ll n, k;
void solve () {
    cin >> n >> k;
    vector <ll> v(n);
    for (int i = 0; i < n; i ++)
        cin >> v[i];
    sort (v.begin(), v.end());
    reverse (v.begin(), v.end());
    ll cnt = 0, mini = v.back();
    while (!v.empty() && v.back() == mini)
        v.pop_back(), cnt ++;
    while (!v.empty()) {
        ll delta = v.back() - mini;
        if (k < delta * cnt)
            break;
        k -= delta * cnt;
        mini = v.back();
        while (!v.empty() && v.back() == mini)
            v.pop_back(), cnt ++;
    }
    mini += k / cnt;
    k %= cnt;
    cnt -= k;
    cout << n * mini - cnt + 1 << "\n";
}
int T;
int main () {
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> T;
    while (T --) {
        solve ();
    }
    return 0;
}
