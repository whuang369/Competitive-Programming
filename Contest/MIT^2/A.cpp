#include <iostream>
#include <set>
#include <map>
using namespace std;
const int N = 1e5 + 5;
int T, n, m, a[N], b[N], c[N];
int main () {
    cin >> T;
    while (T --) {
        cin >> n >> m;
        map <set <int>, int> mp, mp2;
        int od = 0;
        for (int i = 1; i <= m; i ++) {
            cin >> a[i] >> b[i] >> c[i];
            set <int> cur, cur2;
            cur2.insert(a[i]);
            cur2.insert(b[i]);
            cur2.insert(c[i]);
            mp[cur2] ++;
        }
        for (int i = 1; i <= m; i ++) {
            set <int> cur, cur2;
            cur2.insert(a[i]);
            cur2.insert(b[i]);
            cur2.insert(c[i]);
            vector <int> v;
            for (int x : cur2)
                v.push_back(x);
            int len = (int)(v.size());
            for (int k = 1; k < (1 << len); k ++) {
                cur.clear();
                for (int j = 0; j < len; j ++)
                    if (k & (1 << j))
                        cur.insert(v[j]);
                mp2[cur2] += mp[cur];
            }
        }
        for (int i = 1; i <= m; i ++) {
            set <int> cur, cur2;
            cur2.insert(a[i]);
            cur2.insert(b[i]);
            cur2.insert(c[i]);
            mp[cur2] += mp2[cur2];
            mp[cur2] --;
            mp2[cur2] = 0;
        }
        if (m % 2 == 1) {
            cout << "YES\n";
            for (int i = 1; i <= n; i ++)
                cout << "1 ";
            cout << "\n";
        } else {
            int ok = 0;
            for (int i = 1; i <= m; i ++) {
                set <int> cur;
                cur.insert (a[i]);
                cur.insert (b[i]);
                cur.insert (c[i]);
                if (mp[cur] % 2 == 1) {
                    cout << "YES\n";
                    for (int j = 1; j <= n; j ++)
                        if (j != a[i] && j != b[i] && j != c[i])
                            cout << "0 ";
                        else
                            cout << "1 ";
                    cout << "\n";
                    ok = 1;
                    break ;
                }
            }
            if (ok == 0) {
                cout << "NO\n";
            }
        }
    }
    return 0;
}