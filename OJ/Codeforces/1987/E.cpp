#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e3 + 5;
const ll INF = 1e18;
ll n, a[N], ans;
vector <int> v[N];
priority_queue <pair <ll, ll> > q[N];
void dfs (int x) {
    ll sum = 0;
    for (int y : v[x]) {
        dfs (y);
        while (!q[y].empty()) {
            q[x].push (make_pair (q[y].top().first - 1, q[y].top().second));
            q[y].pop();
        }
        sum += a[y];
    }
    if (v[x].size() == 0) {
        q[x].push(make_pair(0, INF));
        return ;
    }
    if (a[x] <= sum) {
        if (a[x] != sum)
            q[x].push(make_pair (0, sum - a[x]));
        return ;
    }
    ll lft = a[x] - sum;
    while (lft) {
        ll dis, mx;
        dis = -q[x].top().first; mx = q[x].top().second; q[x].pop();
        if (mx > lft) {
            mx -= lft;
            ans += dis * lft;
            q[x].push (make_pair (-dis, mx));
            break ;
        } else {
            ans += dis * mx;
            lft -= mx;
        }
    }
}
void solve () {
    cin >> n;
    ans = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        while (!q[i].empty())
            q[i].pop();
        v[i].clear();
    }
    for (int i = 2; i <= n; i ++) {
        int p;
        cin >> p;
        v[p].push_back (i);
    }
    dfs (1);
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