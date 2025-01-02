#include <bits/stdc++.h>
using namespace std;
void solve () {
    vector<int> nums;
    int m, k;
    cin >> m >> k;
    for (int i = 0; i < m; i ++) {
        int x;
        cin >> x;
        nums.push_back (x);
    }


    int n = nums.size();
    int mx = 0;
    vector <int> sum(k);
    for (int md = 0; md < k; md ++) {
        for (int i = 0; i < k; i ++)
            sum[i] = 0;
        for (int i = 0; i < n; i ++) {
            int ot = md - (nums[i] % k);
            if (ot < 0)
                ot += k;
            sum[(nums[i] % k)] = max (sum[(nums[i] % k)], sum[ot] + 1);
            mx = max (mx, sum[(nums[i] % k)]);
        }
    }
    cout << mx << "\n";
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