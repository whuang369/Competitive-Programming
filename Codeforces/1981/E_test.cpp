#include <bits/stdc++.h>
#define L first
#define R second
#define val second
#define ll long long
using namespace std;
int n;
void solve () {
    cin >> n;
    cout << n - ans << "\n";
}
int main () {
    ios::sync_with_stdio (false);
    cin.tie (0);
    cout.tie (0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve ();
    }
}