#include <bits/stdc++.h>
using namespace std;

int t, n, m, d, k;

int main() {
    scanf("%d", &t);
    
    while (t--) {
        scanf("%d", &n);
        scanf("%d", &m);
        
        d = -1000000;
        while (--n) {
            scanf("%d", &k);
            d = max(d, m - k);
            
            if (k > m)
                m = k;
        }
        
        printf("%d\n", d);
    }
    
    return 0;
}
