#include <bits/stdc++.h>
using namespace std;

int t, b1, b2;
long long n, m, k;

int main() {
    bool f = true;
    scanf("%d", &t);
    
    while (t--) {
        if (!f)
            printf("\n");
            
        scanf("%lld", &n);
        for (long long i = 1; i <= 9876543210LL / n; ++i) {
            m = i * n;
            b1 = b2 = 0;
            k = i;
            
            bool c = false;
            while (k) {
                if (b1 & (1 << (k % 10))) {
                    c = true;
                    break;
                } else {
                    b1 |= (1 << (k % 10));
                    k /= 10;
                }
            }
            
            if (!c) {
                k = m;
                
                while (k) {
                    if (b2 & (1 << (k % 10))) {
                        c = true;
                        break;
                    } else {
                        b2 |= (1 << (k % 10));
                        k /= 10;
                    }
                }
                
                if (!c) 
                    printf("%lld / %lld = %lld\n", m, i, n);
            }
            
        }
            
        f = false;
    }
    
    return 0;
}
