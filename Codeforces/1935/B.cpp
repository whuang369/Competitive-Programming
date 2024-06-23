#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
void solve () {
    cin >> n;
    vector <int> a(n), mexf(n), exi(n + 2);
    int now = 0;
    for (int i = 0; i < n; i ++)
        cin >> a[i];
    for (int i = 0; i < n; i ++) {
        exi[a[i]] = 1;
        while (exi[now])
            now ++;
        mexf[i] = now;
    }
    for (int i = 0; i <= n + 1; i ++)
        exi[i] = 0;
    now = 0;
    for (int i = n - 1; i >= 1; i --) {
        exi[a[i]] = 1;
        while (exi[now])
            now ++;
        if (mexf[i - 1] == now) {
            cout << "2\n";
            cout << 1 << " " << i << "\n";
            cout << i + 1 << " " << n << "\n";
            return ;
        }
    }
    cout << "-1\n";
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