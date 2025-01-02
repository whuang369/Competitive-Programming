#include <bits/stdc++.h>
using namespace std;

#ifdef local
#include<local/debug>
#else
#define dbg(...)
#endif


using i64 = long long;

const int N = 1e5 + 5;
int x, y, cnt;
pair <int, int> p[N];

set <int> s;

void mk (int x, int step) {
    if (step > cnt) {
        s.insert (x);
        return ;
    }
    int mul = 1;
    mk (x, step + 1);
    for (int i = 1; i <= p[step].second; i ++) {
        mul *= p[step].first;
        mk (x * mul, step + 1);
    }
    return ;
}

void solve() {
    cin >> x >> y;
    int ans = 0;
    int xx = x;
    cnt = 0;
    int now = 2;
    while (xx != 1) {
        int ok = 0;
        // cout << "stuck" << endl;
        for (; now * now <= xx; now ++)
            if (xx % now == 0) {
                p[++ cnt].first = now;
                p[cnt].second = 0;
                while (xx % now == 0) {
                    p[cnt].second ++;
                    xx /= now;
                }
                ok = 1;
                break ;
            }
        if (!ok) {
            if (xx != 1) {
                p[++ cnt].first = xx;
                p[cnt].second = 1;
                break ;
            }
        }
    }
    s.clear ();
    mk (1, 1);
    for (auto i : s) {
        if (x / i < y)
            break ;
        if (x % i == 0) {
            ans = i;
        }
    }
    cout << ans << '\n';
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