#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main() {
    while (cin >> n, n) {
        cin.ignore();
        int mi = 25;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int co = 0;
            getline(cin, s);
            
            for (int j = 0; j < 25; ++j)
                if (s[j] != 'X')
                    ++co;
                    
            mi = min(co, mi);
            sum += co;
        }
        
        cout << sum - n * mi << "\n";
    }
    
    return 0;
}
