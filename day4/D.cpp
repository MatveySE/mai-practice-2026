#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <functional>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        string a;
        cin >> a;

        vector<int> next_land(n + 2, -1);
        vector<int> cost(n + 2, 0);
        int last_land = n + 1; 
        for (int i = n; i >= 1; --i) {
            if (a[i - 1] == 'C') {
                last_land = -1; 
            }
            else if (a[i - 1] == 'L') {
                last_land = i;
            }
            else { 
                if (last_land != -1) {
                    next_land[i] = last_land;
                    cost[i] = last_land - i; 
                }
                else {
                    next_land[i] = -1;
                }
            }
        }

        const long long INF = 1e18;
        vector<long long> dist(n + 2, INF);
        dist[0] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({ 0, 0 });

        while (!pq.empty()) {
            auto [d, v] = pq.top();
            pq.pop();
            if (d != dist[v]) continue;
            if (v == n + 1) break; 

            for (int jump = 1; jump <= m; ++jump) {
                int y = v + jump;
                if (y > n + 1) break; 

                if (y == n + 1) {
                    if (dist[n + 1] > d) {
                        dist[n + 1] = d;
                        pq.push({ d, n + 1 });
                    }
                }
                else {
                    if (a[y - 1] == 'C') continue; 
                    if (a[y - 1] == 'L') {
                        if (dist[y] > d) {
                            dist[y] = d;
                            pq.push({ d, y });
                        }
                    }
                    else { 
                        int nxt = next_land[y];
                        if (nxt == -1) continue;
                        long long w = cost[y]; 
                        if (dist[nxt] > d + w) {
                            dist[nxt] = d + w;
                            pq.push({ d + w, nxt });
                        }
                    }
                }
            }
        }

        if (dist[n + 1] <= k) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}
