#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int vis[N]; // vis[x] = 0: haven't visit x; vis[x] = 1: visiting x;
                                // vis[x] = 2: finished visiting x.
deque <int> ans; // the topological sorting
bool dfs (int x, vector<vector<int> >& graph) {
    vis[x] = 1;
    for (int y : graph[x]) {
        if (vis[y] == 1) { // if the next node is a node that we are
                                // processing, then there is a cycle
            return false;
        } else if (vis[y] == 2) // there's no need to deal with
                                               // finished note
            continue ;
        else {
            if (!dfs (y, graph)) // if we found that there is a
                  // cycle, then there's no topological sorting
                return false;
        }
    }
    vis[x] = 2;
    ans.push_front(x); // push the current node to the front
    return true;
}
void topological_sorting(vector<vector<int> >& graph) {
    int n = graph.size();
    bool ok = true;
    for (int i = 0; i < n; i ++)
        if (!vis[i])
            if (!dfs (i, graph)) {
                ok = false;
            }
    if (!ok) {
        cout << "No Legal Sorting!\n";
        return ;
    }
    for (int y : ans)
        cout << y << " ";
    return ;
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
    topological_sorting(graph);
    return 0;
}