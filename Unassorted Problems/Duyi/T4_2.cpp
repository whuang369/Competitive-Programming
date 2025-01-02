#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a, b, n, lst[N];
void solve () {
    cin >> a >> b >> n;
    if (a == 2 && b == 2) {
        cout << n << "\n";
        return ;
    }
    if (a < b)
        swap (a, b);
    for (int i = 0; i < n; i ++)
        if (i % a == a - 1)
            lst[i] = 1;
    int now = b - 1;
    while (now < n) {
        while (lst[now])
            now --;
        lst[now] = -1;
        now += b;
        // cout << now << " ";
    }
    int sum = 0;
    for (int i = 0; i < n; i ++) {
        if (lst[i])
            sum ++;
    }
    cout << sum << "\n";
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        solve ();
    }
}