#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 35;
int m, n, a[N];
void solve () {
    cin >> m;
    for (int i = 0; i < 32; i ++)
        if (m & (1 << i))
            a[i] = 1;
        else
            a[i] = 0;
    int l = -1;
    for (int i = 0; i < 32; i ++) {
        if ((l == -1 && a[i] == 1) || (i != 0 && a[i - 1] == 0 && a[i] == 1)) {
            l = i;
        }
        if (i == 0)
            continue ;
        if (a[i - 1] == 1 && a[i] == 0) {
            int r = i - 1;
            if (r - l + 1 == 1)
                continue ;
            a[l] = -1;
            for (int j = l + 1; j <= r; j ++)
                a[j] = 0;
            a[r + 1] = 1;
            l = r + 1;
        }
    }
    cout << "32\n";
    for (int i = 0; i < 32; i ++) {
        cout << a[i] << " ";
    }
    cout << "\n";
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
    return 0;
}