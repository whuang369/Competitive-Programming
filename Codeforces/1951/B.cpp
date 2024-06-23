#include <bits/stdc++.h>
using namespace std;
void solve () {
    int n, k;
    cin >> n >> k;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    int fb = n + 1;
    for (int i = 1; i <= n; i ++)
        if (a[i] > a[k]) {
            fb = i;
            break ;
        }
    if (fb > k)
        cout << fb - 2 << "\n";
    else {
        int ans1 = 0;
        swap (a[k], a[1]);
        for (int i = 2; i <= n; i ++)
            if (a[i] < a[1])
                ans1 ++;
            else
                break ;
        swap (a[1], a[k]);
        int ans2 = -1;
        swap (a[fb], a[k]);
        for (int i = 1; i < fb; i ++)
            if (a[i] > a[fb]) {
                ans2 = 0;
                break ;
            }
        if (ans2 == -1) {
            ans2 = 0;
            if (fb != 1)
                ans2 ++;
            for (int i = fb + 1; i <= n; i ++)
                if (a[i] < a[fb])
                    ans2 ++;
                else
                    break ;
        }
        cout << max (ans1, ans2) << "\n";
    }
    return ;
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