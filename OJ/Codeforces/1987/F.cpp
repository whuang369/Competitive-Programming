#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e2 + 5;
int n, a[N];
void solve () {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    int ans = 0;
    while (1) {
        int ok = 0;
        for (int i = n - 1; i >= 1; i --) {
            if (a[i] == i) {
                ok = i;
                break ;
            }
        }
        if (!ok)
            break;
        ans ++;
        for (int i = ok + 2; i <= n; i ++)
            a[i - 2] = a[i];
        n -= 2;
    }
    cout << ans << "\n";
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