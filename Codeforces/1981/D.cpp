#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
const int N = 1e5 + 5;
map <pair <int, int>, int> mp;
int n, a[N], mx = -1, kk[2] = {0, 0};
void dfs (int step) {
    int x = a[step - 1];
    mx = max (mx, step - 1);
    if (step == 23) {
        for (int i = 1; i <= 22; i ++)
            cout << a[i] <<"";
    }
    for (int i = 1; i <= n; i ++) {
        if (i == x)
            continue ;
        if (mp[make_pair (i, x)])
            continue ;
        a[step] = i;
        mp[make_pair (i, x)] = mp[make_pair (x, i)] = 1;
        dfs (step + 1);
        mp[make_pair (i, x)] = mp[make_pair (x, i)] = 0;
    }
    return ;
}
void dfs2 (int step) {
    int x = a[step - 1];
    if (step - 1 == 14) {
        for (int i = 1; i < step; i ++)
            cout << a[i] << " ";
        cout << "\n";
    }
    for (int i = 1; i <= n; i ++) {
        if (i == x)
            continue ;
        if (mp[make_pair (i, x)] == 1)
            continue ;
        a[step] = i;
        mp[make_pair (i, x)] = mp[make_pair (x, i)] = 1;
        dfs (step + 1);
        mp[make_pair (i, x)] = mp[make_pair (x, i)] = 0;
    }
    return ;
}
void solve () {
    cin >> n;
    mx = -1;
    mp.clear();
    a[1] = 1;
    dfs (2);
    dfs2 (2);
    cout << n << ":" << mx << "\n";
}
int main () {
    ios::sync_with_stdio (0);
    cin.tie (0);
    cout.tie (0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve ();
    }
}