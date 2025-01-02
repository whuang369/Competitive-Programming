#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int dp[N], lst[N];
void solve () {
    ifstream infile; 
    // infile.open("10000-english-no-swears.txt"); 
    // string s;
    // int n = 8000;
    // vector <string> v(n);
    // for (int i = 0; i < n; i ++) {
    //     cin >> v[i];
    // }
    // for (int i = 0; i < n; i ++)
    //     dp[i] = 1;
    // int v1[26], v2[26];
    // for (int i = n - 1; i >= 0; i --) {
    //     if (dp[i] >= 10) {
    //         int now = i;
    //         while (now < n && now >= 0) {
    //             cout << v[now] << "\n";
    //             now = lst[now];
    //         }
    //         break ;
    //     }
    //     for (int j = i - 1; j >= 0; j --) {
    //         string s1 = v[i], s2 = v[j];
    //         if (s1.size() < s2.size())
    //             continue ;
    //         if (s1.size() > (s2.size() + 2))
    //             continue ;
    //         for (int k = 0; k < 26; k ++)
    //             v1[k] = v2[k] = 0;
    //         for (int k = 0; k < s1.size(); k ++)
    //             v1[s1[k] - 'a'] ++;
    //         for (int k = 0; k < s2.size(); k ++)
    //             v2[s2[k] - 'a'] ++;
    //         int ok = 1;
    //         for (int k = 0; k < 26; k ++)
    //             if (v1[k] < v2[k]) {
    //                 ok = 0;
    //                 break ;
    //             }
    //         if (!ok)
    //             continue;
    //         if (dp[j] < dp[i] + 1) {
    //             lst[j] = i;
    //             dp[j] = dp[i] + 1;
    //         }
    //     }
    // }
    // infile.close();
    /*
    a
    at
    art
    rate
    later
    rental
    rentals
    relations
    relationship
    relationships
    */
    string s[10] = {"relationships", "relationship", "relations", "rentals", "rental", "later", "rate", "art", "at", "a"};
    int n;
    cin >> n;
    for (int i = n - 1; i >= 0; i --)
        cout << s[i] << " ";
    cout << "\n";
}
int main () {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        solve ();
    }
}