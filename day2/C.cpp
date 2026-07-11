#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 
using namespace std;
 
int main() {
    string s;
    cin >> s;
    string rev = s;
    reverse(rev.begin(), rev.end());
 
    s = s + "#" + rev;
 
    int n = s.size();
    vector<int> pi(n, 0);
 
    int j = 0;
 
    for (int i = 1; i < n; i++) {
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
 
        if (s[i] == s[j])
            j++;
 
        pi[i] = j;
    }
 
    int ans = pi[n-1];
    cout << ans;
 
    return 0;
}
