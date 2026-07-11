#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int N;
    cin >> N;
 
    vector<long long> dp(N + 1);
    dp[1] = 0;
 
    for (int i = 2; i <= N; ++i) {
        long long best = dp[i - 1] + i;
        if (i % 2 == 0) {
            best = min(best, dp[i / 2] + i);
        }
        if (i % 3 == 0) {
            best = min(best, dp[i / 3] + i);
        }
        dp[i] = best;
    }
 
    cout << dp[N] << '\n';
    return 0;
}
