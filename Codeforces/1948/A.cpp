#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve () {
    int n;
    cin >> n;
    if (n % 2) {
        cout << "NO\n";
        return ;
    }
    cout << "YES\nAA";
    for (int i = 1; i < n / 2; i ++)
        cout << (i % 2 ? "BB" : "AA");
    cout << "\n";
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