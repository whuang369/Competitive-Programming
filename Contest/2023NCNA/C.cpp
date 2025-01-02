#include <bits/stdc++.h>
using namespace std;
string s;
void solve() {
    char c;
    while (cin >> c) {
        if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
            continue ;
        if (c < 'a' || c > 'z')
            c += 'a' - 'A';
        s = s + c;
    }
    // cout << s << "\n";
    int n = s.size();
    for (int i = 0; i < n; i ++) {
        if (i + 1 < n && s[i] == s[i + 1]) {
            cout << "Palindrome\n";
            return ;
        }
        if (i + 2 < n && s[i] == s[i + 2]) {
            cout << "Palindrome\n";
            return ;
        }
    }
    cout << "Anti-palindrome\n";
    return ;
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