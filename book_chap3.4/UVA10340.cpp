#include <bits/stdc++.h>
using namespace std;

string s1, s2;

int main() {
    while (cin >> s1 >> s2) {
        if (cin.eof())
            break;
            
        int si = 0;
        int sj = 0;
        
        while (si != s1.length() && sj != s2.length()) {
            if (s1[si] == s2[sj])
                ++si;
            ++sj;
        }
        
        if (si == s1.length())
            cout << "Yes\n";
        else cout << "No\n";
    }
    
    return 0;
}
