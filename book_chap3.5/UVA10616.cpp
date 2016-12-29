#include <bits/stdc++.h>
using namespace std;

int n, q, d, m;
int a[205];
int b[205];
long long dp[22][12];

int main() {
    int c = 1;
    while (scanf("%d %d", &n, &q), n || q) {
        for (int i = 0; i < n; ++i) 
            scanf("%d", a + i);
        
        printf("SET %d:\n", c++);
        
        for (int x = 1; x <= q; ++x) {
            memset(dp, 0, sizeof(dp));
            scanf("%d %d", &d, &m);
            for (int i = 0; i < n; ++i)
                b[i] = ((a[i] % d) + d) % d;
                
            dp[0][0] = 1;
            for (int i = 0; i < n; ++i)
                for (int k = m; k >= 1; --k) 
                    for (int j = 0; j < d; ++j) 
                        dp[(j + b[i]) % d][k] += dp[j][k - 1];    
                        
            printf("QUERY %d: %lld\n", x, dp[0][m]);        
        }
    }
    
    return 0;
}
