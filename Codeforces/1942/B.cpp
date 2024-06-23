#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e3 + 5;
int n, k;
void solve () {
    cin >> n;
    vector <int> a(n + 1), p(n + 1);
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    int mn = n;
    for (int i = n; i >= 1; i --) {
        p[i] = mn - a[i];
        mn = min (mn, p[i]);
    }
    for (int i = 1; i <= n; i ++)
        cout << p[i] << " ";
    cout << "\n";
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