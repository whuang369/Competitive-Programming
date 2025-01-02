#include <bits/stdc++.h>
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 2e5 + 5;
ll n, q, w[N];
pair <ll, ll> p[N];
void solve () {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> p[i].F >> p[i].S;
        ll temp = p[i].F & p[i].S;
        w[i] = 0;
        for (int j = 30; j >= 0; j --)
            if ((1ll << j) & temp) 
                w[i] = 1;
            }
    }
    cin >> q;
    while (q --) {
        
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
    return 0;
}