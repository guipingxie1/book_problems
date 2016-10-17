#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, x, y, r;
    while (cin >> n >> m, n || m) {
        bitset<1000001> b;
        bitset<1000001> b2;
        
        bool failed = false;
        while (n--) {
            cin >> x >> y;
            
            if (!failed) {
                if (b.test(x))
                    failed = true;
                b.set(x, 1);
                
                if (b2.test(y))
                    failed = true;
                b2.set(y, 1);
                
                for (int i = x + 1; i < y; ++i) {
                    if (b.test(i))
                        failed = true;
                        
                    if (b2.test(i))
                        failed = true;
                        
                    b.set(i, 1);
                    b2.set(i, 1);   
                }
            }
        }
        
        while (m--) {
            cin >> x >> y >> r;
            
            if (!failed) {
                int k = x;
                
                while (k <= 1000000 && !failed) {
                    if (b.test(k))
                        failed = true;
                    b.set(k, 1);
                    
                    for (int i = 1; i < y - x - 1 && ((k + i) <= 1000000); ++i) {
                        if (b.test(k + i))
                            failed = true;
                            
                        if (b2.test(k + i))
                            failed = true;
                            
                        b.set(k + i, 1);  
                        b2.set(k + i, 1);   
                    }
                    
                    if (k + y - x <= 1000000) {
                        if (b2.test(k + y - x))
                            failed = true;
                        b2.set(k + y - x, 1);
                    }
                        
                    k += r;
                }
            }
        }
        
        if (failed)
            cout << "CONFLICT\n";
        else cout << "NO CONFLICT\n";
    }
    
    return 0;
}
