#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main() {
    while (cin >> n, n) {
        cin >> s;
        int l = s.length() / n;
        
        for (int i = 0; i < n; ++i) 
            for (int j = l - 1; j >= 0; --j)
                cout << s[j + i * l]; 
        cout << "\n";
    }
    
    return 0;
}
