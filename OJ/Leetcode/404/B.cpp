#include <bits/stdc++.h>
using namespace std;
void solve () {
    vector<int> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        nums.push_back (x);
    }


    n = nums.size();
    int sum[2] = {0, 0}, mx[2] = {0, 0};
    for (int i = 0; i < n; i ++) {
        if (nums[i] & 1) {
            sum[1] ++;
            mx[1] = max (mx[1], mx[0] + 1);
        } else {
            sum[0] ++;
            mx[0] = max (mx[0], mx[1] + 1);
        }
    }
    // cout << mx[0] << " " << mx[1] << "\n";
    cout << max (max (sum[0], sum[1]), max (mx[0], mx[1])) << "\n";
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