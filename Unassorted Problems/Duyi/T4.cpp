#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a, b, n, lst[N], cnt, pre = 7, mn = N, mn2 = N;
bool check (vector <int> v) {
    int disa = 0, disb = 0, now = 0;
    while (now < n) {
        disa ++;
        disb ++;
        if (v[now] == 1)
            disa = 0;
        if (v[now] == -1)
            disb = 0;
        if (disa >= a || disb >= b)
            return false;
        now ++;
    }
    return true;
}
void mk (int x) {
    if (x == n) {
        vector <int> ls;
        for (int i = 0; i < n; i ++)
            ls.push_back (lst[i]);
        if (check (ls)) {
            int sum = 0;
            for (int i = 0; i < n; i ++)
                if (lst[i])
                    sum ++;
            mn = min (mn, sum);
            int pok = 1;
            for (int i = 0; i < n; i ++)
                if (i % a == a - 1 && lst[i] != 1)
                    pok = 0;
                else if (i % a != a - 1 && lst[i] == 1)
                    pok = 0;
            if (pok) {
                mn2 = min (mn2, sum);
            }
        }
        return ;
    }
    lst[x] = 0;
    mk (x + 1);
    lst[x] = -1;
    mk (x + 1);
    lst[x] = 1;
    mk (x + 1);
}
void solve () {
    cin >> a >> b >> n;
    mk (0);
    cout << mn << " " << mn2 << "\n";
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