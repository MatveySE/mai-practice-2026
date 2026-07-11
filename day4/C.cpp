

    #include <iostream>
    #include <vector>
    using namespace std;
     
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
     
        int t;
        cin >> t;
        while (t--) {
            int n, m, k;
            cin >> n >> m >> k;
     
            vector<int> p;
            p.reserve(n);
     
            for (int i = n; i >= k; --i) {
                p.push_back(i);
            }
     
            for (int i = m + 1; i <= k - 1; ++i) {
                p.push_back(i);
            }
     
            for (int i = 1; i <= m; ++i) {
                p.push_back(i);
            }
     
            for (int i = 0; i < n; ++i) {
                if (i) cout << ' ';
                cout << p[i];
            }
            cout << '\n';
        }
     
        return 0;
    }
