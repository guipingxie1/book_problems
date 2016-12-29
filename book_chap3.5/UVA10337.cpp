#include <bits/stdc++.h>
using namespace std;

int t, n;

int a[12][1005];
int dp[12][1005];

int main() {
    scanf("%d", &t);
    
    while (t--) {            
        scanf("%d", &n);
        int m = n / 100;
        
        for (int i = 0; i < 10; ++i)
            for (int j = 0; j < m; ++j)
                scanf("%d", &a[9 - i][m - 1 - j]);
                
        memset(dp, -1, sizeof(dp));
        dp[0][0] = 30 - a[0][0];
        dp[1][0] = 60 - a[1][0];
        for (int i = 1; i < m; ++i) {
            dp[0][i] = min(dp[0][i - 1] + 30, dp[1][i - 1] + 20) - a[0][i];
                        
            if (dp[9][i - 1] != -1 && dp[8][i - 1] != -1) {
                dp[9][i] = min(dp[8][i - 1] + 60, dp[9][i - 1] + 30) - a[9][i];
            } else if (dp[8][i - 1] != -1) {
                dp[9][i] = dp[8][i - 1] + 60 - a[9][i];
            }
            
            for (int j = 1; j < 9; ++j) {
                if (dp[j + 1][i - 1] != -1) {
                    dp[j][i] = min(min(dp[j - 1][i - 1] + 60, dp[j][i - 1] + 30), dp[j + 1][i - 1] + 20) - a[j][i];
                } else if (dp[j][i - 1] != -1 && dp[j - 1][i - 1] != -1) {
                    dp[j][i] = min(dp[j - 1][i - 1] + 60, dp[j][i - 1] + 30) - a[j][i];                    
                } else if (dp[j - 1][i - 1] != -1) {
                    dp[j][i] = dp[j - 1][i - 1] + 60 - a[j][i];
                }                                
            }
        }
        
        printf("%d\n\n", dp[0][m - 1]);
    }
    
    return 0;
}
