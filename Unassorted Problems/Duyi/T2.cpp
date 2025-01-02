#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 19863;
int vis[N], win[N][2];
void solve () {

}
int enc (string s) {
    int sum = 0;
    for (int i = 0; i < s.size(); i ++)
        if (s[i] == '.')
            sum = sum * 3;
        else if (s[i] == 'X')
            sum = sum * 3 + 1;
        else
            sum = sum * 3 + 2;
    return sum;
}
int check (string s) {
    if (s[0] == s[3] && s[3] == s[6]) {
        if (s[0] == 'O')
            return 1;
        else if (s[0] == 'X')
            return -1;
    }
    if (s[1] == s[4] && s[4] == s[7]) {
        if (s[1] == 'O')
            return 1;
        else if (s[1] == 'X')
            return -1;
    }
    if (s[2] == s[5] && s[5] == s[8]) {
        if (s[2] == 'O')
            return 1;
        else if (s[2] == 'X')
            return -1;
    }
    if (s[0] == s[1] && s[1] == s[2]) {
        if (s[0] == 'O')
            return 1;
        else if (s[0] == 'X')
            return -1;
    }
    if (s[3] == s[4] && s[4] == s[5]) {
        if (s[3] == 'O')
            return 1;
        else if (s[3] == 'X')
            return -1;
    }
    if (s[6] == s[7] && s[7] == s[8]) {
        if (s[6] == 'O')
            return 1;
        else if (s[6] == 'X')
            return -1;
    }
    if (s[0] == s[4] && s[4] == s[8]) {
        if (s[0] == 'O')
            return 1;
        else if (s[0] == 'X')
            return -1;
    }
    if (s[2] == s[4] && s[4] == s[6]) {
        if (s[2] == 'O')
            return 1;
        else if (s[2] == 'X')
            return -1;
    }
    return 0;
}
void dfs (string s) {
    
}
void init () {
    
}
int main () {
    init ();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        solve ();
    }
}