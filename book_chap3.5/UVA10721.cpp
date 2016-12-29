#include <bits/stdc++.h>
using namespace std;

int n, b, m;
long long dp[52][52][52];

int main() {
    while (scanf("%d %d %d", &n, &b, &m) != EOF) {
        memset(dp, 0, sizeof(dp));
        
        dp[1][1][1] = 1;        
        for (int i = 2; i <= n; ++i)
            for (int j = 1; j <= b; ++j)
                for (int k = 1; k <= min(m, i); ++k) {
                    dp[i][j][1] += dp[i - 1][j - 1][k];
                    
                    if (k != 1)
                        dp[i][j][k] = dp[i - 1][j][k - 1];
                }
                
        long long sum = 0;
        for (int k = 1; k <= m; ++k)
            sum += dp[n][b][k];
            
        printf("%lld\n", sum);
    }
    
    return 0;
}
