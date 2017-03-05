#include <bits/stdc++.h>
using namespace std;

int t, n, m, q, r, c, p;
char a[105][105];
char k;

bool w() {
    if (r - p >= 0 && r + p < n && c - p >= 0 && c + p < m) {
        for (int i = r - p; i <= r + p; ++i)
            for (int j = c - p; j <= c + p; ++j)
                if (a[i][j] != k)
                    return false;
                    
        return true;
    }
    
    return false;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &n, &m, &q);
        printf("%d %d %d\n", n, m, q);
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                scanf(" %c", &a[i][j]);
                
        while (q--) {
            scanf("%d %d", &r, &c);
            k = a[r][c];
            
            p = 1;
            
            while (w())
                ++p;
            
            printf("%d\n", 1 + 2 * (p - 1));
        }
    }
    
    return 0;
}
