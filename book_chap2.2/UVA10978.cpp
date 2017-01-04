#include <bits/stdc++.h>
using namespace std;

bool b[55];
string s[55][2];
string sol[55];
int n, k;

int main() {
    while (cin >> n, n) {
        for (int i = 0; i < n; ++i)
            cin >> s[i][0] >> s[i][1];
            
        memset(b, false, sizeof(b));
        
        int be = 0;
        for (int i = 0; i < n; ++i) {
            k = s[i][1].length();
            
            while (k) {
                if (!b[be])
                    --k;
                    
                if (!k)
                    break;
                
                be = (be + 1) % n;
            }   
            
            b[be] = true; 
            sol[be] = s[i][0];
        }
        
        for (int i = 0; i < n - 1; ++i)
            cout << sol[i] << " ";
        cout << sol[n - 1] << "\n";
    }
    
    return 0;
}
