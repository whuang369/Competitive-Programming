#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD = 1e9 + 7, N = 3e5 + 5, MOD1 = 998244353;
const ll B = 1e4 + 3, B1 = 233;
int n, m;
ll pw[N], pw1[N];
int get_hash(const string& s) {
    int res = 0;
    for (int i = 0; i < s.size(); ++i) {
        res = ((ll)res * B + s[i]) % MOD;
    }
    return res;
}
int get_hash1(const string& s) {
    int res = 0;
    for (int i = 0; i < s.size(); ++i) {
        res = ((ll)res * B1 + s[i]) % MOD1;
    }
    return res;
}
void init () {
    pw[0] = 1;
    for (int i = 1; i <= N - 5; i ++)
        pw[i] = pw[i - 1] * B % MOD;
    pw1[0] = 1;
    for (int i = 1; i <= N - 5; i ++)
        pw1[i] = pw1[i - 1] * B1 % MOD1;
}
void solve () {
    cin >> n >> m;
    vector <string> s(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> s[i];
        s[i] = '0' + s[i];
    }
    map <pair <ll, ll>, int> mp;
    int ans = 0;
    string ans_sol;
    for (int j = 1; j <= m; j ++) {
        string cur_sol = "";
        for (int i = 1; i <= n; i ++)
            if (s[i][j] == '1')
                cur_sol += '1';
            else
                cur_sol += '0';
        vector <ll> fr(n + 1), bk(n + 1), fr1(n + 1), bk1(n + 1);
        for (int i = 1; i <= n; i ++) {
            fr[i] = (fr[i - 1] * B % MOD + cur_sol[i - 1]) % MOD;
            fr1[i] = (fr1[i - 1] * B1 % MOD1 + cur_sol[i - 1]) % MOD1;
        }
        bk[n] = cur_sol[n - 1] % MOD;
        bk1[n] = cur_sol[n - 1] % MOD1;
        for (int i = n - 1; i >= 1; i --) {
            bk[i] = (bk[i + 1] + (ll)cur_sol[i - 1] * pw[n - i] % MOD) % MOD;
            bk1[i] = (bk1[i + 1] + (ll)cur_sol[i - 1] * pw1[n - i] % MOD1) % MOD1;
        }
        for (int i = 1; i <= n; i ++) {
            ll cur_tag = fr[i - 1] * pw[n - (i - 1)] % MOD;
            cur_tag = (cur_tag + (i == n ? 0 : bk[i + 1])) % MOD;
            cur_tag %= MOD;
            cur_tag += (ll)((cur_sol[i - 1] == '1' ? '0' : '1')) * pw[n - i] % MOD;
            cur_tag %= MOD;
            ll cur_tag1 = fr1[i - 1] * pw1[n - (i - 1)] % MOD1;
            cur_tag1 = (cur_tag1 + (i == n ? 0 : bk1[i + 1])) % MOD1;
            cur_tag1 %= MOD1;
            cur_tag1 += (ll)((cur_sol[i - 1] == '1' ? '0' : '1')) * pw1[n - i] % MOD1;
            cur_tag1 %= MOD1;
            mp[make_pair(cur_tag, cur_tag1)] ++;
            if (mp[make_pair(cur_tag, cur_tag1)] > ans) {
                string temp = cur_sol;
                if (cur_sol[i - 1] == '1')
                    temp[i - 1] = '0';
                else
                    temp[i - 1] = '1';
                ans_sol = temp;
                ans = mp[make_pair(cur_tag, cur_tag1)];
            }
        }
    }
    cout << ans << "\n" << ans_sol << "\n";
}
int main () {
    init ();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve ();
    }
    return 0;
}