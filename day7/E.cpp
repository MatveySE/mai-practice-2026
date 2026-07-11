#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        for (int k = n; k >= 1; --k) {
            vector<int> diff(n + 1, 0);
            int cur = 0;
            bool ok = true;

            for (int i = 0; i < n; ++i) {
                cur += diff[i];
                bool isZero = (s[i] == '0' && cur % 2 == 0) ||
                    (s[i] == '1' && cur % 2 == 1);
                if (isZero) {
                    if (i + k > n) {
                        ok = false;
                        break;
                    }
                    cur++;
                    diff[i + k]--;
                }
            }

            if (ok) {
                cout << k << '\n';
                break;
            }
        }
    }

    return 0;
}
