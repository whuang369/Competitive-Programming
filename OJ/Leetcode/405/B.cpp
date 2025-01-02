#include <bits/stdc++.h>
using namespace std;
vector<string> validStrings(int n) {
    vector <string> ret;
    for (int i = 0; i < (1 << n); i ++) {
        string cur = "";
        for (int j = 0; j < n; j ++)
            if (i & (1 << j))
                cur += "1";
            else
                cur += "0";
        int ok = 1;
        for (int j = 0; j + 1 < n; j ++)
            if (cur[j] == '0' && cur[j + 1] == '0') {
                ok = 0;
                break;
            }
        if (ok)
            ret.push_back(cur);
    }
    return ret;
}
void init () {
    int n; cin >> n;
    validStrings (n);
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init ();
}