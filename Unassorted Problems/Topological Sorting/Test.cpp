#include <bits/stdc++.h>
using namespace std;
int n;
vector <int> mul (vector <int> a, vector <int> b) {
    vector <int> c(n + 1);
    for (int i = 1; i <= n; i ++)
        c[i] = a[b[i]];
    return c;
}
int main () {
    n = 6;
    vector <int> f, g, h;
    int f1[] = {0, 6, 4, 2, 1, 5, 3};
    int h1[] = {0, 4, 3, 6, 2, 5, 1};
    int g1[] = {0, 3, 5, 6, 2, 4, 1};
    for (int i = 0; i <= n; i ++)
        f.push_back(f1[i]), g.push_back(g1[i]), h.push_back(h1[i]);
    vector <int> ans = mul (g, g);
    ans = mul (ans, g);
    ans = mul (ans, f);
    for (int x : ans)
        cout << x << " ";
}