#include <bits/stdc++.h>
using namespace std;

long long t, n, r, i, k, m;

int main() {
    scanf("%lld", &t);
    
    while (t--) {
        scanf("%lld", &n);
        
        if (n <= 0) {
            printf("0\n");
        } else {
            r = k = 0;
            i = 1;
            while (1) {
                m = (n / i - n / (i + 1));
                if (m == 1)
                    break;
                
                r += i * m;
                k += m;
                ++i;
            }
            
            for (int j = 1; j <= n - k; ++j)
                r += n / j;
            
            printf("%lld\n", r);
        }
    }
    
    return 0;
}
