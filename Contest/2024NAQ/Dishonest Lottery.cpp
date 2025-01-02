#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 55;
int n, sum[N];
void solve () {
    cin >> n;
    for (int i = 1; i <= 10 * n; i ++) {
        int x;
        for (int j = 1; j <= 5; j ++) {
            cin >> x;
            sum[x] ++;
        }
    }
    vector <int> ans;
    for (int i = 1; i <= 50; i ++)
        if (sum[i] > 2 * n)
            ans.push_back (i);
    if (ans.size() == 0)
        cout << "-1\n";
    else {
        for (int x : ans)
            cout << x << " ";
        cout << "\n";
    }
}
int main () {
    ios::sync_with_stdio (0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        solve ();
    }
}