#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, ansnum, dp[2][N];
string s[2];
void solve () {
    cin >> n;
    for (int i = 0; i < 2; i ++) {
        cin >> s[i];
        for (int j = 0; j < n; j ++)
            dp[i][j] = 0;
    }
    ansnum = 0;
    int sum = 1;
    for (int i = 1; i < n; i ++)
        if (s[0][i] > s[1][i - 1])
            break ;
        else if (s[0][i] < s[1][i - 1])
            ansnum = i, sum = 1;
        else
            sum ++;
    for (int i = 0; i <= ansnum; i ++)
        cout << s[0][i];
    for (int i = ansnum; i < n; i ++)
        cout << s[1][i];
    cout << "\n" << sum << "\n";
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