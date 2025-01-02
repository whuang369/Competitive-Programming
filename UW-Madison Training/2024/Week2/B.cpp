#include <bits/stdc++.h>
using namespace std;
double n;
bool dfs (int x, double now, double lft) {
    if (x > 20 || lft == 0)
        return true;
    if (now * 2 < lft)
        return dfs (x + 1, now / 3.0, lft - now * 2);
    else if (lft < now)
        return dfs (x + 1, now / 3.0, lft);
    else
        return false;
}
double getin () {
    string s;
    cin >> s;
    if (s == "END")
        exit(0);
    if (s == "1")
        return 1.0;
    if (s == "0")
        return 0.0;
    double now = 0.1, sum = 0.0;
    for (int i = 2; i < s.size(); i ++, now *= 0.1)
        sum += (double)(s[i] - '0') * now;
    return sum;
}
void solve () {
    n = getin();
    if (dfs (0, 1.0 / 3.0, n))
        cout << "MEMBER\n";
    else
        cout << "NON-MEMBER\n";
}
void init () {
}
int main () {
    init ();
    ios::sync_with_stdio (0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T) {
        solve ();
    }
}