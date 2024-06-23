#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, mxm;
void solve () {
    cin >> n >> mxm;
    vector <pair <ll, ll> > p(n);
    for (int i = 0; i < n; i ++)
        cin >> p[i].second >> p[i].first;
    sort (p.begin(), p.end());
    ll ans = 0;
    for (int l = 0; l < n; l ++) {
        priority_queue<ll> q;
        ll sum = 0, num = 0, bsum = 0;
        // sum += p[l].second;
        // num ++;
        // if (sum <= mxm)
        //     ans = max (ans, num);
        // if (l == n - 1)
        //     break ;
        // sum += p[l + 1].second;
        // num ++;
        // if (sum + p[l + 1].first - p[l].first <= mxm)
        //     ans = max (ans, num);
        for (int r = l; r < n; r ++) {
            sum += p[r].second;
            num ++;
            q.push (p[r].second);
            bsum = p[r].first - p[l].first;
            while (!q.empty() && sum + bsum > mxm) {
                num --;
                sum -= q.top();
                q.pop ();
            }
            if (sum + bsum <= mxm)
                ans = max (ans, num);
        }
    }
    cout << ans << "\n";
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