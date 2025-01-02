#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
const int N = 1e5 + 5;
pair <int, int> p[N];
int n, cnt;
vector <int> v[N];
void solve () {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> p[i].first >> p[i].second;
    sort (p + 1, p + n + 1);
    for (int i = 1; i <= n; i ++) {
        if (p[i].first != p[i - 1].first)
            cnt ++;
        v[cnt].push_back (p[i].second);
    }
    db mul = 0;
    for (int i = 1; i <= cnt; i ++) {
        if (v[i].size() < 2)
            continue ;
        int haf = v[i].size() / 2;
        int r = v[i].size() - 1, l = haf - 1;
        for (int j = 1; j <= haf; j ++) {
            mul += log (db(v[i][r])) - log (db (v[i][l]));
            r --;
            l --;
        }
    }
    cout << fixed << setprecision (20) << mul << "\n";
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