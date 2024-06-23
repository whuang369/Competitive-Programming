#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int n, vis[2][N];
pair <int, int> nxt (char c) {
    if (c == '<')
        return make_pair (0, -1);
    if (c == '>')
        return make_pair (0, 1);
    return make_pair (0, 0);
}
void solve () {
    cin >> n;
    string c[2];
    cin >> c[0] >> c[1];
    for (int i = 0; i < n; i ++)
        vis[0][i] = vis[1][i] = 0;
    queue <pair <int, int> > q;
    int now = 1;
    q.push(make_pair (0, 0));
    vis[0][0] = 1;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        // cout << x << " " << y << "\n";
        q.pop ();
        if ((x + y) & 1) {
            int dx = nxt(c[x][y]).first + x, dy = nxt(c[x][y]).second + y;
            if (!vis[dx][dy])
                q.push(make_pair (dx, dy));
            vis[dx][dy] = 1;
        } else {
            int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i ++) {
                int xx = dx[i] + x, yy = dy[i] + y;
                if (xx < 0 || yy < 0 || xx >= 2 || yy >= n)
                    continue ;
                if (vis[xx][yy])
                    continue ;
                q.push(make_pair(xx, yy));
                vis[xx][yy] = 1;
            }
        }
    }
    if (vis[1][n - 1])
        cout << "YES\n";
    else
        cout << "NO\n";
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