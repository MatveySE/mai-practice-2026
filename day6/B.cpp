#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> c(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> c[i][j];

    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }

    int total = 1 << n;
    const int INF = 1e9;
    vector<vector<int>> dp(total, vector<int>(n, INF));
    dp[1][0] = 0;

    for (int mask = 0; mask < total; ++mask) {
        for (int i = 0; i < n; ++i) {
            if (!(mask & (1 << i)) || dp[mask][i] == INF) continue;
            for (int j = 0; j < n; ++j) {
                if (mask & (1 << j)) continue;
                int newMask = mask | (1 << j);
                int val = dp[mask][i] + c[i][j];
                if (val < dp[newMask][j])
                    dp[newMask][j] = val;
            }
        }
    }

    int full = total - 1;
    int ans = INF;
    for (int i = 1; i < n; ++i)
        ans = min(ans, dp[full][i] + c[i][0]);

    cout << ans << '\n';
    return 0;
}
