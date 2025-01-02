#include <bits/stdc++.h>
using namespace std;
int nex[100000][26], cnt;
  int exist[100000];

    void insert(string s, int l, int val) {
        int p = 0;
        for (int i = 0; i < l; i++) {
            int c = s[i] - 'a';
            if (!nex[p][c])
                nex[p][c] = ++cnt; 
            p = nex[p][c];
        }
        if (exist[p])
            exist[p] = min (exist[p], val);
        else
            exist[p] = val;
    }

    bool static cmp (pair <string, int> x, pair <string, int> y) {
        return x.first.size() < y.first.size();
    }
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        vector <int> dp(target.size() + 1);
        int m = words.size();
        for (int i = 0; i < m; i ++) {
            reverse (words[i].begin(), words[i].end());
            insert (words[i], words[i].size(), costs[i]);
        }

        string s = "";
        for (int i = 0; i < target.size(); i ++) {
            dp[i] = -1;
            s += target[i];
            int p = 0, lst = -1;
            for (int k = 0; k < s.size(); k++) {
                int c = s[s.size() - k - 1] - 'a';
                if (!nex[p][c])
                    break ;
                p = nex[p][c];
                if (exist[p] != 0) {
                    // cout << i << " " << k << "\n";
                    k ++;
                    if (k != i + 1 && dp[i - k] == -1) {
                        k --;
                        continue ;
                    }
                    if (lst == -1)
                        lst = (k == i + 1 ? exist[p] : dp[i - k] + exist[p]);
                    else
                        lst = min (lst, (k == i + 1 ? exist[p] : dp[i - k] + exist[p]));
                    k --;
                }
            }
            dp[i] = lst;
            // cout << dp[i] << "\n";
        }
        return dp[target.size() - 1];
    }
void init () {
    string target;
    vector<string> words;
    vector<int> costs;
    string s;
    cin >> s;
    target = s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> s;
        words.push_back(s);
    }
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        costs.push_back(x);
    }
    int ans = minimumCost(target, words, costs);
    cout << ans << "\n";
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init ();
}