#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int n, a[N];
void solve () {
    cin >> n;
    int nze = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        if (a[i] != 0)
            nze = 1;
    }
    if (!nze) {
        cout << "0\n";
        return ;
    }
    int l = 1, r = n;
    while (a[l] == 0)
        l ++;
    while (a[r] == 0)
        r --;
    for (int i = l; i <= r; i ++) {
        if (a[i] == 0) {
            cout << "2\n";
            return ;
        }
    }
    cout << "1\n";
    return ;
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