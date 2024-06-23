#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 45;
int n, k, a[N], c[N];
void solve () {
    cin >> n >> k;
    if (k >= n) {
        int fi = (n + 1) / 2, se = n - fi;
        for (int i = 1; i <= fi; i ++)
            cout << se + i << " ";
        for (int i = 1; i <= se; i ++)
            cout << i << " ";
        cout << "\n1\n";
        for (int i = 1; i <= n; i ++)
            cout << "1 ";
        cout << "\n";
        return ;
    }
    int ans = 0;
    for (int i = 1; i <= n; i += k) {
        ans ++;
        int r = i + k - 1;
        if (r > n)
            k = n - i + 1;
        int fi = (k + 1) / 2, se = k - fi;
        int now = i;
        for (int j = 1; j <= fi; j ++)
            a[now] = se + i + j - 1, c[now] = ans, now ++;
        for (int j = 1; j <= se; j ++)
            a[now] = i + j - 1, c[now] = ans, now ++;
    }
    for (int i = 1; i <= n; i ++)
        cout << a[i] << " ";
    cout << "\n" << ans << "\n";
    for (int i = 1; i <= n; i ++)
        cout << c[i] << " ";
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