#include <iostream>
using namespace std;

#ifdef local
#include<local/debug>
#else
#define dbg(...)
#endif


using i64 = long long;

const int N = 1e5 + 5;

int n, k;

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        for (int j = 0; j < k; j ++)
            cout << char ('a' + j);
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}