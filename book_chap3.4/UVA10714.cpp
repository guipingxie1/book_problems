#include <bits/stdc++.h>
using namespace std;

int t, n, m, x, y, k;

int main() {
    scanf("%d", &t);
    
    while (t--) {
        scanf("%d %d", &n, &m);
        x = 0;
        y = 0;
        
        while (m--) {
            scanf("%d", &k);
            x = max(x, min(n - k, k));
            y = max(y, max(n - k, k));
        } 
        
        printf("%d %d\n", x, y);
    }
    
    return 0;
}
