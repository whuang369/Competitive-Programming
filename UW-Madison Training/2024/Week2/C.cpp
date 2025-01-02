#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int n, m, sx, sy, tx, ty, vis[N][N], d[N][N];
int dx[] = {1, 1, -1, -1, 2, 2, -2, -2}, dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
void solve () {
    queue <pair <int, int> > que;
    // cin >> n >> m >> sx >> sy >> tx >> ty;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            vis[i][j] = 0;
    que.push (make_pair (sx, sy));
    vis[sx][sy] = 1;
    d[sx][sy] = 0;
    while (!que.empty()) {
        pair <int, int> p = que.front();
        que.pop ();
        int x = p.first;
        int y = p.second;
        for (int i = 0; i < 8; i ++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx < 1 || xx > n || yy < 1 || yy > m || vis[xx][yy])
                continue ;
            vis[xx][yy] = 1;
            d[xx][yy] = d[x][y] + 1;
            que.push(make_pair (xx, yy));
            if (xx == tx && yy == ty) {
                cout << d[xx][yy] << "\n";
                return ;
            }
        }
    }
    if (!vis[tx][ty]) {
        cout << "impossible\n";
    } else
        cout << d[tx][ty] << "\n";
}
int main () {
    ios::sync_with_stdio (0);
    cin.tie(0);
    int T = 3;
    // cin >> T;
    while (cin >> n >> m >> sx >> sy >> tx >> ty) {
        solve ();
    }
}