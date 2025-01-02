#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e3 + 5;
ll n, k, val[N][N];
vector <ll> dp[N];
pair <ll, pair <ll, ll> > mk (ll x, ll y, ll z) {
    pair <ll, pair <ll, ll> > ret;
    ret.first = x;
    ret.second.first = y;
    ret.second.second = z;
    return ret;
}
void solve () {
    cin >> n >> k;
    for (int i = 1; i <= n; i ++) {
        dp[i].clear();
        for (int j = i; j <= n; j ++)
            cin >> val[i][j];
    }
    vector <ll> tempv; tempv.push_back(0);
    dp[0] = tempv;
    for (int i = 1; i <= n; i ++) {
        priority_queue <pair <ll, pair <ll, ll> > > q;
        q.push(mk(dp[i - 1][0], i - 1, 0));
        for (int j = i - 2; j >= -1; j --)
            if (j >= 0)
                q.push(mk(dp[j][0] + val[j + 2][i], j, 0));
            else
                q.push(mk(val[j + 2][i], j, 0));
        while (!q.empty()) {
            pair <ll, pair <ll, ll> > temp = q.top();
            ll v = temp.first, index = temp.second.first, num = temp.second.second;
            q.pop ();
            dp[i].push_back (v);
            if (dp[i].size() == k)
                break ;
            if (index <= 0 || num + 1 >= dp[index].size())
                continue;
            if (index == i - 1)
                q.push(mk(dp[index][num + 1], index, num + 1));
            else
                q.push(mk(dp[index][num + 1] + val[index + 2][i], index, num + 1));
        }
    }
    for (ll x : dp[n])
        cout << x << " ";
    cout << "\n";
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