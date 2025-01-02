#include <bits/stdc++.h>
using namespace std;
int n, k;
void solve () {
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 0; i < n; i ++) {
        int x = s[i] - 'a';
        if (!x)
            continue;
        if (26 - x > k)
            continue;
        k -= 26 - x;
        s[i] = 'a';
    }
    cout << s << "\n";
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        solve ();
    }
}