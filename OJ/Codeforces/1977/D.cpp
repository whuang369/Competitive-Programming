#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e3 + 5;
int n, m;
void solve () {
    cin >> n >> m;
    string ans_s;
    for (int i = 0; i < n; i ++)
        ans_s += '0';
    vector <vector<int> > a(n + 1);
    vector <int> s(m + 1);
    for (int i = 1; i <= n; i ++) {
        string s;
        cin >> s;
        vector <int> v(m + 1);
        for (int j = 1; j <= m; j ++)
            if (s[j - 1] == '0')
                v[j] = 0;
            else
                v[j] = 1;
        a[i] = v;
    }
    int fans = 0;
    for (int j = 1; j <= m; j ++) {
        for (int i = 1; i <= n; i ++)
            s[j] += a[i][j];
        if (s[j] == 1)
            fans ++;
    }
    for (int J = 1; J <= m; J ++) {
        vector <vector <int> > psb;
        vector <int> sum(n + 1);
        int ans = 0;
        for (int j = 1; j <= m; j ++) {
            if (s[j] != s[J] && s[j] != s[J] + 2)
                continue ;
            vector <int> cur (n + 1);
            if (s[j] == s[J]) {
                int ok = 1;
                for (int i = 1; i <= n; i ++)
                    if (a[i][j] != a[i][J]) {
                        ok = 0;
                        break ;
                    }
                ans += ok;
            } else {
                int ok = 1;
                for (int i = 1; i <= n; i ++)
                    cur[i] = a[i][j];
                for (int i = 1; i <= n; i ++)
                    if (a[i][J] == 1 && cur[i] != a[i][J]) {
                        ok = 0;
                        break ;
                    }
                if (!ok)
                    continue ;
                for (int i = 1; i <= n; i ++)
                    if (a[i][J] == 0 && cur[i] == 1) {
                        sum[i] ++;
                    }
            }
        }
        int mx = 0, pos = 0;
        for (int i = 1; i <= n; i ++) {
            if (mx < sum[i])
                pos = i;
            mx = max (mx, sum[i]);
        }
        ans += mx;
        if (fans < ans) {
            string sol = "";
            for (int i = 0; i < n; i ++)
                if (a[i + 1][J] == 1 || i + 1 == pos)
                    sol += '1';
                else
                    sol += '0';
            fans = ans;
            ans_s = sol;
        }
    }
    cout << fans << "\n" << ans_s << "\n";
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