#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int test = 0; test < t; ++test) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> b(m);
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }

        unordered_map<int, int> freq_b;
        for (int x : b) {
            freq_b[x]++;
        }

        unordered_map<int, int> freq_win;
        int matches = 0;
        long long ans = 0;

        for (int i = 0; i < m; ++i) {
            int x = a[i];
            if (freq_win[x] < freq_b[x]) {
                matches++;
            }
            freq_win[x]++;
        }
        if (matches >= k) {
            ans++;
        }

        for (int i = m; i < n; ++i) {
            int x = a[i];
            if (freq_win[x] < freq_b[x]) {
                matches++;
            }
            freq_win[x]++;

            int y = a[i - m];
            freq_win[y]--;
            if (freq_win[y] < freq_b[y]) {
                matches--;
            }
            if (freq_win[y] == 0) {
                freq_win.erase(y);
            }

            if (matches >= k) {
                ans++;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
