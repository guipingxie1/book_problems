#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    
    while (t--) {
        cin >> n;
        int a[n];
        int ma = 0;
        for (int i = 0; i < n; ++i) 
            cin >> a[i];
            
        set<int> s;
        int i = 0;
        int j = 0;
        for (int k = 0; k < n; ++k) {
            if (s.find(a[k]) != s.end()) {
                ma = max(ma, (int)s.size());   
                
                while (i < k) {
                    if (a[i] == a[k]) {
                        ++i;
                        break;
                    }
                        
                    s.erase(a[i++]);
                }
            } else {
                s.insert(a[k]);
            }
        }
            
        cout << max(ma, (int)s.size()) << "\n";
    }
    
    return 0;
}
