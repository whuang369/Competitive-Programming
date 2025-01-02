#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int n, a[N][2], ans[2], sum[3];
void solve () {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i][0];
    for (int i = 1; i <= n; i ++)
        cin >> a[i][1];
    ans[0] = ans[1] = sum[0] = sum[1] = sum[2] = 0;
    for (int i = 1; i <= n; i ++) {
        int x = a[i][0], y = a[i][1];
        if (x == y)
            sum[x + 1] ++;
        else {
            if (x > y)
                ans[0] += x;
            else
                ans[1] += y;
        }
    }
    while (sum[0]) {
        sum[0] --;
        if (ans[0] > ans[1])
            ans[0] --;
        else
            ans[1] --;
    }
    while (sum[2]) {
        sum[2] --;
        if (ans[0] > ans[1])
            ans[1] ++;
        else
            ans[0] ++;
    }
    cout << min (ans[0], ans[1]) << "\n";
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