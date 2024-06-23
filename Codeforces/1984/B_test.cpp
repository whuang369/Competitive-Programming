#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll sto (string s) {
    ll ret = 0;
    for (int i = 0; i < s.size(); i ++)
        ret = ret * 10 + s[i] - '0';
    return ret;
}
string ltos (ll x) {
    string ret = "";
    while (x) {
        ret += (x % 10) + '0';
        x /= 10;
    }
    return ret;
}
bool check (ll x) {
    while (x) {
        if (x % 10 < 5)
            return false;
        x /= 10;
    }
    return true;
}
void solve () {
    map <int, int> mp;
    for (ll i = 5000; i <= 10000; i ++)
        for (ll j = 5000; j <= 10000; j ++)
            if (check (i) && check (j) && ltos (i).size() == ltos(j).size())
                mp[i + j] = 1;
    for (int i = 10000; i <= 100000; i ++)
        if (mp[i]) {
            cout << i << "\n";
        }
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        solve ();
    }
}