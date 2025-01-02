#include <bits/stdc++.h>
using namespace std;
int n, k;
void solve () {
    cin >> n >> k;
    k *= 2;
    vector <int> v1(n), v2(n);
    map <int, int> mp;
    for (int i = 0; i < n; i ++) {
        cin >> v1[i];
        mp[v1[i]] ++;
    }
    for (int i = 0; i < n; i ++)
        cin >> v2[i];
    int ans = 0;
    queue <int> v11, v12, v13;
    for (int i = 1; i <= n; i ++) {
        int tims = mp[i];
        if (tims == 0)
            v13.push (i);
        if (tims == 1)
            v12.push (i);
        if (tims == 2)
            v11.push (i);
    }
    vector <int> ans1, ans2;
    while (ans1.size() < k - 1 && !v13.empty()) {
        ans1.push_back (v11.front());
        ans1.push_back (v11.front());
        ans2.push_back (v13.front());
        ans2.push_back (v13.front());
        v11.pop ();
        v13.pop ();
    }
    while (ans1.size() < k) {
        ans1.push_back (v12.front());
        ans2.push_back (v12.front());
        v12.pop ();
    }
    for (int x : ans1)
        cout << x << " ";
    cout << "\n";
    for (int x : ans2)
        cout << x << " ";
    cout << "\n";
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