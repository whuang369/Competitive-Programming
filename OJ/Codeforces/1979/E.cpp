#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int n, d, diss[N];
pair <int, int> p[N];
vector <pair <int, int> > v[N];
void solve () {
    cin >> n >> d;
    set <int> s;
    map <int, int> mp;
    map <pair <int, int>, int> exip;
    for (int i = 0; i < n; i ++) {
        cin >> p[i].first >> p[i].second;
        exip[p[i]] = i + 1;
    }
    s.clear ();
    for (int i = 0; i < n; i ++)
        s.insert (p[i].first - p[i].second);
    int cnt = 0;
    for (int dis : s) {
        cnt ++;
        mp[dis] = cnt;
        diss[cnt] = dis;
        v[cnt].clear();
    }
    for (int i = 0; i < n; i ++)
        v[mp[p[i].first - p[i].second]].push_back(p[i]);
    for (int i = 1; i <= cnt; i ++)
        sort (v[i].begin(), v[i].end());
    for (int i = 1; i <= cnt; i ++) {
        int dis = diss[i];
        if (mp[dis - d]) {
            int lnum = mp[dis - d];
            int now = 0;
            for (auto pp : v[i]) {
                if (exip[make_pair (pp.first + d / 2, pp.second + d / 2)]) {
                    while (now < v[lnum].size() && v[lnum][now].first < pp.first - d / 2)
                        now ++;
                    if (now < v[lnum].size() && v[lnum][now].first >= pp.first - d / 2 && v[lnum][now].first <= pp.first) {
                        pair <int, int> tp;
                        tp.first = v[lnum][now].first;
                        tp.second = v[lnum][now].second;
                        cout << exip[pp] << " " << exip[make_pair (pp.first + d / 2, pp.second + d / 2)] << " " << exip[tp] << "\n";
                        return ;
                    }
                }
            }
        }
        if (mp[dis + d]) {
            int rnum = mp[dis + d];
            int now = 0;
            for (auto pp : v[i]) {
                if (exip[make_pair (pp.first + d / 2, pp.second + d / 2)]) {
                    while (now < v[rnum].size() && v[rnum][now].first < pp.first + d / 2)
                        now ++;
                    if (now < v[rnum].size() && v[rnum][now].first >= pp.first + d / 2 && v[rnum][now].first <= pp.first + d) {
                        pair <int, int> tp;
                        tp.first = v[rnum][now].first;
                        tp.second = v[rnum][now].second;
                        cout << exip[pp] << " " << exip[make_pair (pp.first + d / 2, pp.second + d / 2)] << " " << exip[tp] << "\n";
                        return ;
                    }
                }
            }
        }
    }
    s.clear ();
    mp.clear ();
    for (int i = 0; i < n; i ++)
        s.insert (p[i].first + p[i].second);
    cnt = 0;
    for (int dis : s) {
        cnt ++;
        mp[dis] = cnt;
        diss[cnt] = dis;
        v[cnt].clear();
    }
    for (int i = 0; i < n; i ++)
        v[mp[p[i].first + p[i].second]].push_back(p[i]);
    for (int i = 1; i <= cnt; i ++)
        sort (v[i].begin(), v[i].end());
    for (int i = 1; i <= cnt; i ++) {
        int dis = diss[i];
        if (mp[dis - d]) {
            int lnum = mp[dis - d];
            int now = 0;
            for (auto pp : v[i]) {
                if (exip[make_pair (pp.first + d / 2, pp.second - d / 2)]) {
                    while (now < v[lnum].size() && v[lnum][now].first < pp.first - d / 2)
                        now ++;
                    if (now < v[lnum].size() && v[lnum][now].first >= pp.first - d / 2 && v[lnum][now].first <= pp.first) {
                        pair <int, int> tp;
                        tp.first = v[lnum][now].first;
                        tp.second = v[lnum][now].second;
                        cout << exip[pp] << " " << exip[make_pair (pp.first + d / 2, pp.second - d / 2)] << " " << exip[tp] << "\n";
                        return ;
                    }
                }
            }
        }
        if (mp[dis + d]) {
            int rnum = mp[dis + d];
            int now = 0;
            for (auto pp : v[i]) {
                if (exip[make_pair (pp.first + d / 2, pp.second - d / 2)]) {
                    while (now < v[rnum].size() && v[rnum][now].first < pp.first + d / 2)
                        now ++;
                    if (now < v[rnum].size() && v[rnum][now].first >= pp.first + d / 2 && v[rnum][now].first <= pp.first + d) {
                        pair <int, int> tp;
                        tp.first = v[rnum][now].first;
                        tp.second = v[rnum][now].second;
                        cout << exip[pp] << " " << exip[make_pair (pp.first + d / 2, pp.second - d / 2)] << " " << exip[tp] << "\n";
                        return ;
                    }
                }
            }
        }
    }
    cout << "0 0 0\n";
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve ();
    }
}