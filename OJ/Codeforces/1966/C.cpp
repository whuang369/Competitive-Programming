#include <bits/stdc++.h>
using namespace std;
int T, n;
void solve () {
    cin >> n;
    vector <int> v(n);
    for (int i = 0; i < n; i ++)
        cin >> v[i];
    sort (v.begin(), v.end());
    int ot1 = 0, winn = 0;
    if (v[0] > 1)
        ot1 = 1;
    else {
        for (int i = 0; i < n - 1; i ++)
            if (v[i + 1] - v[i] > 1) {
                ot1 = 1;
                winn = (v[i]) % 2;
                break ;
            }
    }
    if (ot1)
        cout << (winn % 2 == 1 ? "Bob\n" : "Alice\n");
    else {
        ot1 = v[n - 1];
        if (ot1 & 1)
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }
}
int main () {
    cin >> T;
    while (T --) {
        solve ();
    }
}