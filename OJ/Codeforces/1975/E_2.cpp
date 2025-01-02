#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int n, Q, a[N], blks, col[N], num[N], chl[N], sum2, wtf;
int fa[N];
vector <int> v[N];
void dfs (int x) {
    for (int y : v[x]) {
        if (y == fa[x])
            continue ;
        fa[y] = x;
        dfs (y);
    }
}
void flip (int x) {
    col[x] ^= 1;
    int d = (col[x] == 1 ? 1 : -1);
    blks += d;
    if (col[fa[x]] == 0)
        wtf ++;
    if (chl[x] == 2) {
        num[2] += d;
        sum2 ^= x;
    }
    if (chl[x] > 2)
        num[3] += d;
    if (col[x] == 1) {
        
    }
}
void solve () {
    cin >> n >> Q;
    num[0] = n;
    sum2 = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        num[i] = 0;
        chl[i] = 0;
        col[i] = 0;
    }
    for (int i = 1; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back (y);
        v[y].push_back (x);
    }
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