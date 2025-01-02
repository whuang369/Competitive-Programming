#include <bits/stdc++.h>
using namespace std;
int sum[10];
void solve () {
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j ++) {
            int x = s[j] - '0';
            sum[x] ++;
            sum[x] %= 10;
        }
    }
    for (int i = 0; i < 10; i ++)
        cout << sum[i];
    cout << "\n";
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