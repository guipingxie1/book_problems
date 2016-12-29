#include <bits/stdc++.h>
using namespace std;

int k, n, m, x, y;

int main() {
    while (scanf("%d", &k), k) {
        scanf("%d %d", &n, &m);
        
        for (int i = 0; i < k; ++i) {
            scanf("%d %d", &x, &y);
            
            if (x > n && y > m) {
                printf("NE\n");
            } else if (x < n && y < m) {
                printf("SO\n");
            } else if (x > n && y < m) {
                printf("SE\n");
            } else if (x < n && y > m) {
                printf("NO\n");
            } else {
                printf("divisa\n");
            }
        }
    }
    
    return 0;
}
