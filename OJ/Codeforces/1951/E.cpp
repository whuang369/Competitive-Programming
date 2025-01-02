#include <bits/stdc++.h>
using namespace std;
bool check (string s) {
    int n = s.size();
    for (int i = 0, j = n - 1; i < j; i ++, j --)
        if (s[i] != s[j])
            return true;
    return false;
}
void solve () {
    int n;
    string s;
    cin >> s;
    n = s.size();
    if (check (s)) {
        cout << "YES\n1\n" << s << "\n";
        return ;
    }
    int pos = 0;
    for (int i = 1; i < n; i ++)
        if (s[i] != s[0]) {
            pos = i;
            break ;
        }
    if (!pos) {
        cout << "NO\n";
        return ;
    }
    if (check (s.substr(pos + 1, s.size() - pos - 1))) {
        cout << "YES\n2 " << s.substr(0, pos + 1) << " " << s.substr(pos + 1, s.size() - pos - 1) << "\n";
        return ;
    }
    int cnt = 0;
    for (int i = 1; i < n; i ++)
        if (s[i] != s[0]) {
            cnt ++;
        }
    if (cnt == 1 || pos == 1) {
        cout << "NO\n";
        return ;
    }
    cout << "YES\n2 " << s.substr(0, pos + 2) << " " << s.substr(pos + 2, s.size() - pos - 2) << "\n";
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