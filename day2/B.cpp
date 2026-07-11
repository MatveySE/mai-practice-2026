

    #include <iostream>
    #include <vector>
    #include <string>
     
    using namespace std;
     
    int main() {
        string s;
        cin >> s;
     
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
     
        int period = n - pi[n - 1];
     
        if (n % period == 0)
            cout << period;
        else
            cout << n;
     
        return 0;
    }
