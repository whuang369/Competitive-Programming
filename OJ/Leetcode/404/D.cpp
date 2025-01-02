#include <bits/stdc++.h>
using namespace std;
int minimumDiameterAfterMerge(vector<vector<int> >& edges1, vector<vector<int> >& edges2) {
    int n = edges1.size() + 1;
    int m = edges2.size() + 1;
    vector <int> v[n], g[m];
    for (int i = 0; i < n - 1; i ++) {
        int x = edges1[i][0], y = edges1[i][1];
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 0; i < m - 1; i ++) {
        int x = edges2[i][0], y = edges2[i][1];
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector <int> d11(n), d12(n), d21(m), d22(m);
    queue <int> q;
    int dia11 = 0, dia12 = 0, dia21 = 0, dia22 = 0;
    int dia1 = 0, dia2 = 0;
    d11[0] = 1;
    q.push (0);
    while (!q.empty()) {
        int x = q.front(); q.pop ();
        for (int y : v[x]) {
            if (d11[y])
                continue;
            d11[y] = d11[x] + 1;
            if (d11[dia11] < d11[y]) {
                dia11 = y;
            }
            q.push(y);
        }
    }
    d12[dia11] = 1;
    q.push (dia11);
    while (!q.empty()) {
        int x = q.front(); q.pop ();
        for (int y : v[x]) {
            if (d12[y])
                continue;
            d12[y] = d12[x] + 1;
            dia1 = max (dia1, d12[y]);
            if (d12[dia12] < d12[y]) {
                dia12 = y;
            }
            q.push(y);
        }
    }
    d21[0] = 1;
    q.push (0);
    while (!q.empty()) {
        int x = q.front(); q.pop ();
        for (int y : g[x]) {
            if (d21[y])
                continue;
            d21[y] = d21[x] + 1;
            if (d21[dia21] < d21[y]) {
                dia21 = y;
            }
            q.push(y);
        }
    }
    d22[dia21] = 1;
    q.push (dia21);
    while (!q.empty()) {
        int x = q.front(); q.pop ();
        for (int y : g[x]) {
            if (d22[y])
                continue;
            d22[y] = d22[x] + 1;
            dia2 = max (dia2, d22[y]);
            if (d22[dia22] < d22[y]) {
                dia22 = y;
            }
            q.push(y);
        }
    }
    for (int i = 0; i < n; i ++)
        d11[i] = 0;
    for (int i = 0; i < m; i ++)
        d21[i] = 0;
    d11[dia12] = 1;
    q.push (dia12);
    while (!q.empty()) {
        int x = q.front(); q.pop ();
        for (int y : v[x]) {
            if (d11[y])
                continue;
            d11[y] = d11[x] + 1;
            q.push(y);
        }
    }
    d21[dia22] = 1;
    q.push (dia22);
    while (!q.empty()) {
        int x = q.front(); q.pop ();
        for (int y : g[x]) {
            if (d21[y])
                continue;
            d21[y] = d21[x] + 1;
            q.push(y);
        }
    }
    int mn1 = n, mn2 = m;
    // cout << dia11 << " " << dia12 << " " << dia21 << " " << dia22 << "\n";
    for (int i = 0; i < n; i ++) {
        mn1 = min (mn1, max (d11[i], d12[i]));
        // cout << d11[i] << " " << d12[i] << "\n";
    }
    // cout << "--------------------------\n";
    for (int i = 0; i < m; i ++) {
        mn2 = min (mn2, max (d21[i], d22[i]));
        // cout << d21[i] << " " << d22[i] << "\n";
    }
    return max (mn1 + mn2 - 1, max (dia1 - 1, dia2 - 1));
}
void solve () {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > edges1; vector<vector<int> > edges2;
    for (int i = 0; i < n; i ++) {
        int x; vector <int> temp;
        cin >> x;
        temp.push_back(x);
        cin >> x;
        temp.push_back(x);
        edges1.push_back(temp);
    }
    for (int i = 0; i < m; i ++) {
        int x; vector <int> temp;
        cin >> x;
        temp.push_back(x);
        cin >> x;
        temp.push_back(x);
        edges2.push_back(temp);
    }
    int ans = minimumDiameterAfterMerge (edges1, edges2);
    cout << ans << "\n";
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve();
    }
}