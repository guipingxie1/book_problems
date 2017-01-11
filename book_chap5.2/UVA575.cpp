#include <bits/stdc++.h>
using namespace std;

string s;
long long k, n;

int main() {
    while (cin >> s) {
        if (s.length() == 1 && s[0] == '0')
            break;
            
        k = 0;
        n = 2;
        for (int i = s.length() - 1; i >= 0; --i) {
            k += (s[i] - '0') * (n - 1);
            n <<= 1;
        }
        
        cout << k << "\n";
    }
    
    return 0;
}
