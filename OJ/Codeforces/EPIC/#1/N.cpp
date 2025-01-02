#include <bits/stdc++.h>
using namespace std;
int n;
vector <int> disp (int s, int d, vector <int> v) {
    vector <int> ret;
    int cur = s, num = 1;
    for (int x : v) {
        if (num <= n && cur == x) {
            num ++;
            cur += d;
            continue;
        }
        ret.push_back(x);
    }
    return ret;
}
bool checkv (int s, int d, vector <int> v) {
    int cur = s, num = 1;
    for (int x : v)
        if (num <= n && cur == x) {
            num ++;
            cur += d;
            continue;
        } else if (num > n)
            break ;
    if (num != n + 1)
        return false;
    return true;
}
int s3, d3;
bool checkari (vector <int> v) {
    if (v.size() == 1)
        return true;
    int dis = v[1] - v[0];
    for (int i = 2; i < v.size(); i ++)
        if (v[i] - v[i - 1] != dis)
            return false;
    s3 = v[0];
    d3 = dis;
    return true;
}
int s1, d1, s2, d2;
bool bdis (vector <int> v) {
    int len = v.size();
    // if (v[0] == 11) {
    //     for (int x : v)
    //         cout << x << " ";
    //     cout << "\n";
    // }
    int s = v[0], t = v[len - 1];
    if ((t - s) % (len - 1) == 0) {
        int dis = (t - s) / (len - 1);
        if (checkv (s, dis, v) && checkari (disp (s, dis, v))) {
            s2 = v[0];
            d2 = dis;
            return true;
        }
    }
    vector <int> pdis;
    pdis.push_back (v[1] - v[0]);
    pdis.push_back (v[2] - v[0]);
    pdis.push_back (v[2] - v[1]);
    pdis.push_back (v[3] - v[0]);
    pdis.push_back (v[3] - v[1]);
    pdis.push_back (v[3] - v[2]);
    pdis.push_back (v[len - 1] - v[len - 2]);
    pdis.push_back (v[len - 1] - v[len - 2]);
    pdis.push_back (v[len - 1] - v[len - 4]);
    pdis.push_back (v[len - 2] - v[len - 3]);
    pdis.push_back (v[len - 2] - v[len - 4]);
    pdis.push_back (v[len - 3] - v[len - 4]);
    for (int dis : pdis) {
        // if (v[0] == 11)
        //     cout << dis << "\n";
        if (checkv (s, dis, v) && checkari (disp (s, dis, v))) {
            s2 = v[0];
            d2 = dis;
            return true;
        }
    }
    return false;
}
void solve () {
    cin >> n;
    vector <int> a(3 * n);
    for (int i = 0; i < 3 * n; i ++)
        cin >> a[i];
    sort (a.begin(), a.end());
    // vector <int> aa = disp (a[0], 18, a);
    // for (int x : aa) {
    //     cout << x << " ";
    // }
    // cout << "\n";
    // for (int x : a) {
    //     cout << x << " ";
    // }
    // cout << "\n";
    for (int i = 1; i < 3 * n; i ++) {
        int dis = a[i] - a[0];
        if (checkv (a[0], dis, a) && bdis (disp (a[0], dis, a))) {
            s1 = a[0];
            d1 = dis;
            break ;
        }
    }
    cout << s1 << " " << d1 << " " << s2 << " " << d2 << " " << s3 << " " << d3 << "\n";
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