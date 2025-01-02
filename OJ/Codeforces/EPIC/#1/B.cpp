#include <bits/stdc++.h>
using namespace std;
int pos[45];
void solve () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++, cout << "\n")
        for (int j = 1; j <= n; j ++)
            if (pos[i + j])
                cout << '+';
            else
                cout << '-';
    
}
void init () {
    vector <int> v;
    v.push_back (1);
    v.push_back (2);
    v.push_back (4);
    v.push_back (8);
    v.push_back (16);
    v.push_back (32);
    for (int i = 0; i < 6; i ++)
        for (int j = 0; j < 6; j ++) {
            int x = v[i] + v[j];
            pos[x] = 1;
        }
}
int main () {
    init ();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        solve ();
    }
}