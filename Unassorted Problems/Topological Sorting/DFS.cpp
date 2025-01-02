#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int uns[N], vis[N];
void dfs (int x, vector<vector<int> >& graph) {
    vis[x] = 1;
    for (int y : graph[x]) {
        if (uns[y] == 1)
            uns[x] = 1;
        if (vis[y] == 1) {
            uns[x] = uns[y] = 1;
        } else if (vis[y] == 2)
            continue ;
        else {
            dfs (y, graph);
            if (uns[y] == 1)
                uns[x] = 1;
        }
    }
    vis[x] = 2;
    return ;
}
vector<int> eventualSafeNodes(vector<vector<int> >& graph) {
    int n = graph.size();
    for (int i = 0; i < n; i ++)
        if (!vis[i])
            dfs (i, graph);
    vector <int> ans;
    for (int i = 0; i < n; i ++)
        if (!uns[i])
            ans.push_back(i);
    return ans;
}


int n;
vector<vector<int> > graph;
int main () {
    cin >> n;
    for (int i = 0; i < n; i ++) {
        int len;
        cin >> len;
        vector <int> cur;
        for (int j = 0; j < len; j ++) {
            int x;
            cin >> x;
            cur.push_back (x);
        }
        graph.push_back(cur);
    }
    vector <int> ans = eventualSafeNodes(graph);
    for (int x : ans)
        cout << x << " ";
    return 0;
}