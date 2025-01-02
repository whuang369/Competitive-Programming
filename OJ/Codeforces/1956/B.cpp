#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, a[N];
void solve () {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    sort (a + 1, a + n + 1);
    int sum = 0;
    for (int i = 2; i <= n; i ++)
        sum += a[i] == a[i - 1];
    cout << sum << "\n";
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
    return 0;
}