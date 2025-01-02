#include <bits/stdc++.h>
using namespace std;
string solve (string s, int k) {
    int n = s.size();
    string ret = "";
    for (int i = 0; i < n; i ++)
        ret += s[(i + k) % n];
    return ret;
}
void init () {
    string s;
    int k;
    cin >> s >> k;
    auto ans = solve (s, k);
    cout << ans << "\n";
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init ();
}