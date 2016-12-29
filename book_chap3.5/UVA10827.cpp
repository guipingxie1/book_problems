#include <bits/stdc++.h>
using namespace std;

int t, n;

int a[80][80];
int b[160][160];
int c[160];

int main() {
    scanf("%d", &t);
        
    while (t--) {
        scanf("%d", &n);
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &a[i][j]);
         
        int ma = a[0][0];
        int sz = n << 1; 
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                b[i][j] = b[i + n][j] = b[i][j + n] = b[i + n][j + n] = a[i][j];
                
        for (int i = 0; i < n; ++i) {
            memset(c, 0, sz * sizeof(int));
            
            for (int j = i; j < i + n; ++j) {
                for (int k = 0; k < sz; ++k) 
                    c[k] += b[j][k];
                
                for (int o = 0; o < n; ++o) {
                    int m = c[o];
                    int x = c[o];
                    int len = 1;
                    
                    for (int k = o + 1; k < o + n; ++k) {
                        x = max(x + c[k], c[k]);
                        m = max(m, x);
                    } 
                    
                    ma = max(ma, m);
                }
            }
        }
        
        printf("%d\n", ma);
    }
    
    return 0;
}
