#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 105;
int n, m;
void solve () {
    cin >> n >> m;
    if (n >= m && (n - m) % 2 == 0)
        cout << "Yes\n";
    else
        cout << "No\n";
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
    return 0;
}