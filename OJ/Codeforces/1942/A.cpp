#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e3 + 5;
int n, k;
void solve () {
    cin >> n >> k;
    if (n != k && k != 1)
        cout << "-1\n";
    else if (n == k) {
        for (int i = 1; i <= n; i ++)
            cout << "1 ";
        cout << "\n";
    } else {
        for (int i = 1; i <= n; i ++)
            cout << i << " ";
        cout << "\n";
    }
    return ;
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