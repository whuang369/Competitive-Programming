#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve () {
    int n;
    cin >> n;
    vector <ll> a(n);
    int ok = 0;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        if (a[i] != a[0])
            ok ++;
    }
    if (!ok) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        int lft = n - ok;
            for (int i = 0; i < n - 1; i ++) {
                if (a[i] - a[0] != a[n - 1] - a[i + 1]) {
                    for (int j = 0; j <= i; j ++)
                        cout << "B";
                    for (int j = i + 1; j < n; j ++)
                        cout << "R";
                    cout << "\n";
                    return ;
                }
            }
        cout << "\n";
    }
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