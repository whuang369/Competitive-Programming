#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
void solve () {
    cin >> s;
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            sum1 ++;
            sum2 ++;
        }
        if (s[i] == 'y')
            sum1 ++;
    }
    cout << sum2 << " " << sum1 << "\n";
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