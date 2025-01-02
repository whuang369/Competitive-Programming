#include <bits/stdc++.h>
using namespace std;
int numberOfSubmatrices(vector<vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size();
    int sum[n][m][3];
    int ans = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            sum[i][j][0] = sum[i][j][1] = sum[i][j][2] = 0;
            int num = 0;
            if (grid[i][j] == 'X')
                num = 1;
            if (grid[i][j] == 'Y')
                num = 2;
            sum[i][j][num] ++;
            for (int k = 0; k < 3; k ++) {
                if (i > 0 && j > 0) {
                    sum[i][j][k] += sum[i - 1][j][k] + sum[i][j - 1][k] - sum[i - 1][j - 1][k];
                } else if (i > 0)
                    sum[i][j][k] += sum[i - 1][j][k];
                else if (j > 0)
                    sum[i][j][k] += sum[i][j - 1][k];
            }
            if (sum[i][j][1] && sum[i][j][1] == sum[i][j][2])
                ans ++;
        }
    }
    return ans;
}
void init () {
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init ();
}