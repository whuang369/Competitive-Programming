#include <iostream>
#include <set>
#include <map>
#include <queue>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
int T, n, a[N];
int main () {
    cin >> T;
    while (T --) {
        cin >> n;
        ll sum1 = 0, sum2 = 0;
        vector <int> v1;
        priority_queue <pair <int, int> > q;
        for (int i = 1; i <= n; i ++) {
            cin >> a[i];
            if (a[i] == 1)
                sum1 ++, v1.push_back(i);
            else {
                sum2 ++;
                q.push (make_pair (a[i], i));
            }
        }
        vector <int> ans;
        if ((sum1 + sum2) % 2 == 0 || !(sum2 >= sum1 * 3ll - 1)) {
            cout << "NO\n";
            continue ;
        }
        cout << "YES\n";
    }
    return 0;
}