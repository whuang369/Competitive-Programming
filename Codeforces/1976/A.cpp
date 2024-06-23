#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int n;
void solve () {
    cin >> n >> s;
    string t[2] = {"", ""};
    int ls = -1;
    for (int i = 0; i < s.size(); i ++)
        if (s[i] >= '0' && s[i] <= '9') {
            if (ls != -1) {
                cout << "NO\n";
                return ;
            }
            t[0] += s[i];
        } else
            t[1] += s[i], ls = 1;
    for (int i = 1; i < t[0].size(); i ++)
        if (t[0][i - 1] > t[0][i]) {
            cout << "NO\n";
            return ;
        }
    for (int i = 1; i < t[1].size(); i ++)
        if (t[1][i - 1] > t[1][i]) {
            cout << "NO\n";
            return ;
        }
    cout << "YES\n";
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