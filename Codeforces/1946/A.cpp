#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
void solve () {
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i ++)
        cin >> a[i];
    sort (a.begin(), a.end());
    int mid = (int)((n + 1) / 2) - 1, l = mid;
    for (int i = mid; i < n; i ++)
        if (a[i] == a[mid])
            l = i;
        else
            break ;
    cout << l - mid + 1 << "\n";
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