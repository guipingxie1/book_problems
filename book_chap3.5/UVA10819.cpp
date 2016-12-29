#include <bits/stdc++.h>
using namespace std;

int m, n;
int a[105][2];

int dp[11000];

int main() {
    while (scanf("%d %d", &m, &n) != EOF) {
        for (int i = 0; i < n; ++i)
            scanf("%d %d", &a[i][0], &a[i][1]);
            
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
            
        if (m >= 1801) {
            for (int i = 0; i < n; ++i)
                for (int j = m + 200; j >= a[i][0]; --j)
                    if (dp[j - a[i][0]] != -1)
                        dp[j] = max(dp[j], dp[j - a[i][0]] + a[i][1]);
            
            int mi = 0;
            for (int i = 0; i <= m; ++i)
                mi = max(mi, dp[i]);
                
            for (int i = max(m, 2001); i <= m + 200; ++i)
                mi = max(mi, dp[i]);
            
            printf("%d\n", mi);
        } else {
            for (int i = 0; i < n; ++i)
                for (int j = m; j >= a[i][0]; --j)
                    if (dp[j - a[i][0]] != -1)
                        dp[j] = max(dp[j], dp[j - a[i][0]] + a[i][1]);
                        
            int mi = 0;            
            for (int i = 0; i <= m; ++i)
                mi = max(mi, dp[i]);
            
            printf("%d\n", mi);
        }
    }
    
    return 0;
}
