#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int n, q, a[N], b[N], ss[N], oa[N], ob[N];
void solve () {
    string s, t;
    cin >> n >> s >> t;
    for (int i = 1; i <= n; i ++) {
        if (s[i - 1] == '1')
            a[i] = oa[i] = 1;
        else
            a[i] = oa[i] = 0;
        if (t[i - 1] == '1')
            b[i] = ob[i] = 1;
        else
            b[i] = ob[i] = 0;
    }
    for (int i = 1; i + 2 <= n; i ++)
        if (!a[i] && !a[i + 2])
            b[i + 1] = 1;
    for (int i = 1; i + 2 <= n; i ++)
        if (b[i] && b[i + 2])
            a[i + 1] = 1;
    // for (int i = 1; i <= n; i ++)
    //     cout << a[i] << " ";
    // cout << "\n";
    for (int i = 1; i <= n; i ++)
        ss[i] = ss[i - 1] + a[i];
    int q;
    cin >> q;
    while (q --) {
        int l, r;
        cin >> l >> r;
        if (r - l + 1 <= 2) {
            int sum = 0;
            for (int i = l; i <= r; i ++)
                sum += oa[i];
            cout << sum << "\n";
            continue ;
        }
        if (r - l + 1 == 3) {
            int sum = oa[l] + oa[l + 1] + oa[r];
            if (ob[l] && ob[r] && !oa[r - 1])
                sum ++;
            cout << sum << "\n";
            continue;
        }
        int ans = ss[r] - ss[l - 1];
        if (ob[r] != b[r] && oa[r - 1] != a[r - 1])
            ans --;
        if (ob[l] != b[l] && oa[l + 1] != a[l + 1])
            ans --;
        if (oa[r] != a[r])
            ans --;
        if (oa[l] != a[l])
            ans --;
        cout << ans << "\n";
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
}