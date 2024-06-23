#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
string s;
void solve () {
    cin >> n >> s;
    string t = s;
    reverse(t.begin(), t.end());
    string mn = min (s, t);
    int op = -1;
    if (mn == s) {
        if (n % 2)
            op = 1;
        else
            op = 0;
    } else {
        if (n % 2)
            op = 0;
        else
            op = 1;
    }
    string ans = "";
    if (op == 0) {
        ans = mn;
    } else {
        ans = mn;
        reverse(mn.begin(), mn.end());
        ans += mn;
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