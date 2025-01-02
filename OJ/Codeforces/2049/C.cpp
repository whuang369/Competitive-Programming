#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, s, t, a[N];
void solve () {
    cin >> n >> s >> t;
    if (n & 1) {
        a[s] = 2;
        for (int i = s - 1, j = 1; i >= 1; i --, j ^= 1)
            a[i] = j;
        for (int i = s + 1, j = 0; i <= n; i ++, j ^= 1)
            a[i] = j;
        for (int i = 1; i <= n; i ++)
            cout << a[i] << " ";
    } else {
        for (int i = 1; i <= n; i ++)
            a[i] = i & 1;
        if (a[s] == a[t])
            a[s] = 2;
        for (int i = 1; i <= n; i ++)
            cout << a[i] << " ";
    } 
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