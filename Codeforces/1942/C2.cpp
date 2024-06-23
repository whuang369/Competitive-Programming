#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int n;
int md (int x) {
    if (x <= 0)
        return x + n;
    return (x - 1) % n + 1;
}
int x, y;
void solve () {
    cin >> n >> x >> y;
    vector <int> a(x), d(x);
    for (int i = 0; i < x; i ++) {
        cin >> a[i];
    }
    sort (a.begin(), a.end());
    for (int i = 0; i < x - 1; i ++)
        d[i] = a[i + 1] - a[i];
    d[x - 1] = a[0] + n - a[x - 1];/Users/huangwenyuan
    sort (d.begin(), d.end());
    int ans = x + y - 2, oriy = y;
    for (int gap : d) {
        if (gap & 1)
            continue;
        if (y >= gap / 2 - 1)
            y -= gap / 2 - 1, ans += gap / 2;
        else
            break ;
    }
    cout << min (ans + y, n - 2) << "\n";
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