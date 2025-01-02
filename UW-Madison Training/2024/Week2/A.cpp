#include <bits/stdc++.h>
using namespace std;
map <int, string> mp;
void dfs (int x, int val, int sum, string s) {
    if (x == 5) {
        mp[sum + val] = s;
        return ;
    }
    string t = s;
    t = s + " + 4";
    dfs (x + 1, 4, sum + val, t);
    t = s + " - 4";
    dfs (x + 1, -4, sum + val, t);
    t = s + " * 4";
    dfs (x + 1, val * 4, sum, t);
    t = s + " / 4";
    dfs (x + 1, (int)(val / 4), sum, t);
    return ;
}
void solve () {
    int n;
    cin >> n;
    if (mp.count(n)) {
        cout << mp[n] << " = " << n << "\n";;
    } else
        cout << "no solution\n";
}
void init () {
    dfs (2, 4, 0, "4");
}
int main () {
    init ();
    ios::sync_with_stdio (0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve ();
    }
}