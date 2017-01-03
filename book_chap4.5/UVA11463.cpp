#include <bits/stdc++.h>
using namespace std;

int t, n, m, u, v;
int d[105][105];

int main() {
    scanf("%d", &t);
    
    for (int x = 1; x <= t; ++x) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < n; ++j)
                d[i][j] = 1000000;
        
        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &u, &v);
            d[u][v] = d[v][u] = 1;
        }                
        
        scanf("%d %d", &u, &v);
           
        for (int i = 0; i < n; ++i) 
            d[i][i] = 0;
            
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                    
        int mi = 0;
        for (int i = 0; i < n; ++i)
            mi = max(mi, d[u][i] + d[i][v]);
        
        printf("Case %d: %d\n", x, mi);
    }
    
    return 0;
}
