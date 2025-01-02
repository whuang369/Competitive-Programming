#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
int n, k, c, rk[N], sch[N], num[N];
bool cmp (int x, int y) {
    return rk[x] < rk[y];
}
void solve () {
    cin >> n >> k >> c;
    vector <int> ans, wl;
    for (int i = 1; i <= n; i ++) {
        int id, sh;
        cin >> id >> sh;
        rk[id] = i;
        sch[id] = sh;
        if (ans.size() < k) {
            if (num[sh] < c)
                ans.push_back (id), num[sh] ++;
            else
                wl.push_back (id);
        }
    }
    if (ans.size() < k) {
        for (int x : wl) {
            ans.push_back (x);
            if (ans.size() == k)
                break ;
        }
    }
    sort (ans.begin(), ans.end(), cmp);
    for (int x : ans)
        cout << x << "\n";
}
int main () {
    ios::sync_with_stdio (0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        solve ();
    }
}