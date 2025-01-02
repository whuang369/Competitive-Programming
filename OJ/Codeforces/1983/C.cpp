#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int n, pos[4], l[4], r[4];
ll a[4][N], b[4][N], lim[4][2], s[4][N], ss[4][N];
void solve () {
    cin >> n;
    ll tot = 0;
    for (int i = 1; i <= 3; i ++) {
        pos[i] = i;
        tot = 0;
        for (int j = 1; j <= n; j ++) {
            cin >> b[i][j];
            tot += b[i][j];
            s[i][j] = s[i][j - 1] + b[i][j];
        }
        tot = (tot + 2) / 3;
        ll sum = 0;
        for (int j = 1; j <= n; j ++) {
            sum += b[i][j];
            if (sum >= tot) {
                l[i] = j;
                break ;
            }
        }
        sum = 0;
        for (int j = n; j > 0; j --) {
            sum += b[i][j];
            if (sum >= tot) {
                r[i] = j;
                break ;
            }
        }
    }
    do {
        for (int i = 1; i <= 3; i ++) {
            for (int j = 1; j <= n; j ++) {
                a[i][j] = b[pos[i]][j];
                ss[i][j] = s[pos[i]][j];
            }
            lim[i][0] = l[pos[i]];
            lim[i][1] = r[pos[i]];
        }
        int l = lim[1][0] + 1, r = lim[3][1] - 1;
        if (l > r)
            continue ;
        ll cur = ss[2][r] - ss[2][l - 1];
        if (cur >= tot) {
            vector <int> ans;
            for (int i = 1; i <= 3; i ++)
                if (pos[i] == 1) {
                    if (i == 1) {
                        ans.push_back (1);
                        ans.push_back (lim[1][0]);
                    }
                    if (i == 2) {
                        ans.push_back (l);
                        ans.push_back (r);
                    }
                    if (i == 3) {
                        ans.push_back (lim[3][1]);
                        ans.push_back (n);
                    }
                }
            for (int i = 1; i <= 3; i ++)
                if (pos[i] == 2) {
                    if (i == 1) {
                        ans.push_back (1);
                        ans.push_back (lim[1][0]);
                    }
                    if (i == 2) {
                        ans.push_back (l);
                        ans.push_back (r);
                    }
                    if (i == 3) {
                        ans.push_back (lim[3][1]);
                        ans.push_back (n);
                    }
                }
            for (int i = 1; i <= 3; i ++)
                if (pos[i] == 3) {
                    if (i == 1) {
                        ans.push_back (1);
                        ans.push_back (lim[1][0]);
                    }
                    if (i == 2) {
                        ans.push_back (l);
                        ans.push_back (r);
                    }
                    if (i == 3) {
                        ans.push_back (lim[3][1]);
                        ans.push_back (n);
                    }
                }
            for (int x : ans)
                cout << x << " ";
            cout << "\n";
            return ;
        }
    } while (next_permutation (pos + 1, pos + 4));
    cout << "-1\n";
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve();
    }
}