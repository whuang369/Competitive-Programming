#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
ll n, k, a[N], s[N], b[N];
int lb (int x) {
    return x - (x & (x - 1));
}
void opt (int x) {
    if (x == 0)
        return ;
    if (x == 1) {
        for (int i = 1; i <= n; i ++)
            s[i] = a[i];
        return ;
    }
    opt (x - 1);
    vector <int> ss(n + 1);
    for (int i = 1; i <= n; i ++) {
        for (int j = i - lb(i) + 1; j <= i; j ++)
            ss[i] += s[j];
    }
    for (int i = 1; i <= n; i ++)
        s[i] = ss[i];
}
void dfs (int step) {
    if (step > n) {
        for (int i = 1; i <= n; i ++)
            s[i] = a[i];
        opt (k);
        for (int i = 1; i <= n; i ++)
            if (s[i] != b[i])
                return ;
        for (int i = 1; i <= n; i ++)
            cout << a[i] << " ";
        cout << "\n";
        return ;
    }
    for (int i = 0; i <= 8; i ++) {
        a[step] = i;
        dfs (step + 1);
    }
}
void solve () {
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> b[i];
    dfs (1);
}
int main () {
    // ios::sync_with_stdio (0);
    // cin.tie (0);
    // cout.tie (0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve ();
    }
    return 0;
}