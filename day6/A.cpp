#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<long long> a;
long long ans = 0;

void dfs(int idx, int cnt, long long curXor) {
    if (cnt == k) {
        ans = max(ans, curXor);
        return;
    }
    if (idx == n) return;  

    dfs(idx + 1, cnt + 1, curXor ^ a[idx]);

    dfs(idx + 1, cnt, curXor);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    dfs(0, 0, 0);
    cout << ans << '\n';

    return 0;
}
