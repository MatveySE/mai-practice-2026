#include <iostream>
#include <vector>
 
using namespace std;
 
const int MOD = 1000000007;
 
int main() {
    int l, r;
    cin >> l >> r;
 
    vector<int> dp(r + 1, 0);
    dp[1] = 1;
 
    for (int i = 1; i <= r; i++) {
        for (int j = 2 * i; j <= r; j += i) {
            dp[j] = (dp[j] + dp[i]) % MOD;
        }
    }
 
    int ans = 0;
 
    for (int i = l; i <= r; i++) {
        ans += dp[i];
        if (ans >= MOD)
            ans -= MOD;
    }
 
    cout << ans << endl;
 
    return 0;
}
