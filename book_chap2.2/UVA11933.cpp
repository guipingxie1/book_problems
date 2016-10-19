#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned int n;
    while (cin >> n, n) {
        unsigned int a = 0;
        unsigned int b = 0;
        
        bool bb = true;
        for (int i = 0; i < 32; ++i) {
            if (n & (1L << i)) {
                if (bb)
                    b += (1L << i);
                else a += (1L << i);
                
                bb = !bb;
            }
        }
        
        cout << b << " " << a << "\n";
    }    
    
    return 0;
}
