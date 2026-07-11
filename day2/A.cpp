#include <iostream>
#include <string>
using namespace std;
 
int main() {
    string s1, s2;
    cin >> s1 >> s2;
 
 
 
    int pos = (s1 + s1).find(s2);
 
    if (pos == string::npos) {
        cout << -1;
    }
    else {
        int n = s1.size();
        int Sdvig = (n - pos) % n;
        cout << Sdvig;
    }
}
