#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef double db;
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = a; i < (b); ++i)
const int N = 1005;
int n;
string s; 
void solve() {
    cin >> n;
    int cr = 0, sd = 0, o = 0, t = 0, sum[5] = {0, 0, 0, 0, 0}, sumcr[5] = {0, 0, 0, 0, 0}, nj = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> s;
        int tcr = cr;
        if (s[0] == '1' && s[1] == '1')
            cr ++;
        if (s[2] == '1' && s[1] == '1')
            cr ++;
        if (s[3] == '1' && s[2] == '1')
            cr ++;
        if (s[0] == '1' && s[3] == '1')
            cr ++;
        tcr = cr - tcr;
        sumcr[tcr] ++;
        int tsd = sd;
        if (s[0] == '1')
            sd ++;
        if (s[1] == '1')
            sd ++;
        if (s[2] == '1')
            sd ++;
        if (s[3] == '1')
            sd ++;
        tsd = sd - tsd;
        sum[tsd] ++;
        if (tsd == 2 && tcr == 0)
            nj ++;
        if (s[0] == '0')
            o ++;
        if (s[1] == '0')
            o ++;
        if (s[2] == '0')
            o ++;
        if (s[3] == '0')
            o ++;
        if (s[0] == '2')
            t ++;
        if (s[2] == '2')
            t ++;
        if (s[3] == '2')
            t ++;
        if (s[1] == '2')
            t ++;
    }
    if (n == 1) {
        if (s == "1111")
            cout << "Yes\nYes\nYes\n";
        else
            cout << "Yes\nNo\nNo\n";
        return ;
    }
    if (n == 0) {
        cout << "No\n";
        cout << "No\n";
        cout << "No\n";
    }
    cout << "Yes\n";
    if (cr != 4 || sd % 2) {
        cout << "No\n";
        cout << "No\n";
        return ;
    }
    sd /= 2;
    int ok = 0;
    for (int i = 2; i < sd - 1; i ++)
        if (i * (sd - i) == n && sumcr[1] == 4 && sumcr[2] == 0 && sumcr[3] == 0 && sumcr[4] == 0 && sum[2] == 4 && sum[3] == 0 && sum[4] == 0) {
            ok = 1;
            break ;
        }
    if (sum[3] == 2 && nj == n - 2)
        ok = 1;
    if (!ok) {
        cout << "No\nNo\n";
        return ;
    }
    cout << "Yes\n";
    if (o != t)
        cout << "No\n";
    else
        cout << "Yes\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}