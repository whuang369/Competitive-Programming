#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
void solve () {
    cin >> n;
    vector <int> v(n);
    map <int, int> mp;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        mp[x] ++;
    }
    int sum = 0;
    for (int i = 0; i <= n; i ++) {
        sum += (mp[i] == 1);
        if (sum == 2 || mp[i] == 0) {
            cout << i << "\n";
            return ;
        }
    }
}
int main () {
    ios::sync_with_stdio (0);
    cin.tie (0);
    cout.tie (0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve ();
    }
}