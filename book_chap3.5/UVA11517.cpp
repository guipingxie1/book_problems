#include <bits/stdc++.h>
using namespace std;

int t, m, n;
int a[105];
int dp[20005];

int main() {
    scanf("%d", &t);
    
    while (t--) {
        scanf("%d %d", &m, &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", a + i);
            
        for (int i = 0; i <= m + 10000; ++i)
            dp[i] = 100000;
            
        dp[0] = 0;
        
        for (int i = 0; i < n; ++i)
            for (int j = m + 10000; j >= a[i]; --j)
                if (dp[j - a[i]] != 100000)
                    dp[j] = min(dp[j], dp[j - a[i]] + 1);
        
        int idx = 0;            
        for (int i = m; i <= m + 10000; ++i)
            if (dp[i] != 100000) {
                idx = i;
                break;
            }
            
        printf("%d %d\n", idx, dp[idx]);            
    }
    
    return 0;
}
