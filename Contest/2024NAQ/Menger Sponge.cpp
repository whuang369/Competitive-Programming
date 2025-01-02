#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
ll n, exi[N], getin[3][2];
void solve () {
    cin >> n;
    for (int i = 0; i < 3; i ++)
        for (int j = 0; j < 2; j ++)
            cin >> getin[i][j];
    for (int T = 0; T < 3; T ++) {
        ll p = getin[T][0], q = getin[T][1];
        for (int i = 0; i < n; i ++) {
            p *= 3;
            int cur = p / q;
            if (cur == 1) {
                if (p % q == 0 && i != n - 1)
                    exi[i] = exi[i];
                else
                    exi[i] ++;
            }
            p %= q;
        }
    }
    for (int i = 0; i < n; i ++)
        if (exi[i] > 1) {
            cout << "0\n";
            return ;
        }
    cout << "1\n";
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