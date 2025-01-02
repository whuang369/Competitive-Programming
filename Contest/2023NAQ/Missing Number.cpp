#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int sto (string t) {
    int now = 0;
    for (int i = 0; i < t.size(); i ++) {
        now = now * 10 + (t[i] - '0');
    }
    return now;
}
string ito (int x) {
    string ret = "";
    while (x) {
        ret = (char)((x % 10) + '0') + ret;
        x /= 10;
    }
    return ret;
}
set <int> ans;
void chk (int l1, int l2) {
    if (l1 > s.size() || l2 > s.size() || l1 + l2 > s.size())
        return ;
    int a = sto (s.substr (0, l1));
    int b = sto (s.substr (s.size() - l2, l2));
    if (a >= b)
        return ;
    int i = 0, now = a, lst = -1;
    int et = -1;
    while (i < s.size()) {
        int siz = ito (now).size();
        if (i + siz > s.size())
            return ;
        int nxt = sto (s.substr (i, siz));
        if (nxt == now) {
            i += siz;
            now ++;
            lst = now - 1;
            continue ;
        }
        if (et != -1)
            return ;
        siz = ito (now + 1).size();
        nxt = sto (s.substr (i, siz));
        if (nxt == now + 1) {
            et = now;
            i += siz;
            lst = now + 1;
            now += 2;
            continue ;
        }
        return ;
    }
    if (lst != b)
        return ;
    if (et != -1) {
        ans.insert (et);
        return ;
    }
    if (a - 1 >= 1)
        ans.insert (a - 1);
    if (b + 1 <= 99999)
        ans.insert (b + 1);
}
void solve () {
    cin >> s;
    ans.clear ();
    for (int lena = 1; lena <= 5; lena ++)
        for (int lenb = lena; lenb <= 5; lenb ++) {
            chk (lena, lenb);
        }
    if (s.size() <= 5) {
        int x = sto (s);
        if (x - 1 >= 1)
            ans.insert (x - 1);
        if (x + 1 <= 99999)
            ans.insert (x + 1);
    }
    cout << ans.size() << "\n";
    for (int x : ans)
        cout << x << " ";
    cout << "\n";
}
int main () {
    ios::sync_with_stdio (0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve ();
    }
}