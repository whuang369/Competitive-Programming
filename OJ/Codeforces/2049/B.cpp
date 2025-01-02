#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n, ss, sp;
string s;
void solve () {
    cin >> n;
    ss = 0, sp = 0;
    cin >> s;
    for (int i = 0; i < n; i ++)
        if (s[i] == 'p')
            sp ++;
        else if (s[i] == 's')
            ss ++;
    if (s[0] == 's')
        ss --;
    if (s[n - 1] == 'p')
        sp --;
    if (ss != 0 && sp != 0) {
        cout << "NO\n";
        return ;
    }
    cout << "YES\n";
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