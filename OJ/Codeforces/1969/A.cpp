#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 55;
int n, fa[N], p[N], siz[N];
int find (int x) {
    return (x == fa[x] ? x : fa[x] = find (fa[x]));
}
void merge (int x, int y) {
    int xx = find (x), yy = find (y);
    if (xx == yy)
        return ;
    fa[xx] = yy;
    siz[yy] += siz[xx];
    siz[xx] = 0;
    return ;
}
void solve () {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> p[i];
        fa[i] = i;
        siz[i] = 1;
    }
    for (int i = 1; i <= n; i ++)
        merge (i, p[i]);
    int ans = 0;
    vector <int> sizs;
    int exi_2 = 0;
    for (int i = 1; i <= n; i ++)
        if (fa[i] == i) {
            ans ++;
            sizs.push_back(siz[i]);
            if (siz[i] == 2)
                exi_2 = 1;
        }
    sort (sizs.begin(), sizs.end());
    if (sizs.size() >= 2 && sizs[0] == 1 && sizs[1] == 1) {
        cout << "2\n";
    } else {
        if (exi_2)
            cout << "2\n";
        else
            cout << "3\n";
    }
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