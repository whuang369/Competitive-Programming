#include <bits/stdc++.h>
using namespace std;
void solve () {
    int n, k;
    cin >> n >> k;
    if (n - 1 > k)
        cout << n << "\n";
    else
        cout << "1\n";
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