#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
int n, m, s[N];
void solve () {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        int x; cin >> x;
        s[i] = s[i - 1] ^ x;
        // cout << s[i] << " ";
    }
    // cout << "\n";
    int mx = 0;
    for (int pos = 29; pos >= 0; pos --) {
        if (!(m & (1 << pos)))
            continue;
        int sum = 0;
        int mbef = m >> (pos + 1);
        for (int i = 1; i <= n; i ++) {
            int bef = s[i] >> (pos + 1), cur = (s[i] >> pos) & 1;
            if ((mbef | bef) > mbef || cur != 0) {
                if (i == n)
                    sum = -1;
                continue ;
            }
            sum ++;
        }
        mx = max (mx, sum);
    }
    int sum = 0;
    int mbef = m;
    for (int i = 1; i <= n; i ++) {
        int bef = s[i];
        if ((mbef | bef) > mbef) {
            if (i == n)
                sum = -1;
            continue ;
        }
        sum ++;
    }
    mx = max (mx, sum);
    if (mx == 0)
        cout << "-1\n";
    else
        cout << mx << "\n";
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