#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int n, a[N], sum[N];
void solve () {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        sum[i] = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        sum[a[i]] ++;
    }
    for (int i = 1; i <= n; i ++)
        if (sum[a[i]] & 1) {
            cout << "YES\n";
            return ;
        }
    cout << "NO\n";
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