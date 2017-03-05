#include <bits/stdc++.h>
using namespace std;

int t, n, p, q, x;

int main() {
    scanf("%d", &t);
    
    for (int z = 1; z <= t; ++z) {
        scanf("%d %d %d", &n, &p, &q);
        
        int w = 0;
        int c = 0;
        
        while (n--) {
            scanf("%d", &x);
            
            if (w + x <= q && c < p) {
                ++c;
                w += x;
            }
        }
        
        printf("Case %d: %d\n", z, c);
    }
}
