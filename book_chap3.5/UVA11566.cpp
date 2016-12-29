#include <bits/stdc++.h>
using namespace std;

int n, x, t, d, f, m, p;
int a[105][2];
int dp[1105][25];

int main() {
    while (scanf("%d %d %d %d", &n, &x, &t, &d), n || x || t || d) {
        for (int i = 0; i < d; ++i) {
            scanf("%d %d", &a[i][0], &a[i][1]);
            
            for (int j = 0; j < n; ++j) {
                scanf("%d", &f);
                a[i][1] += f;
            }
        }
        
        memset(dp, -1, sizeof(dp));
        dp[t * (n + 1)][0] = 0;
        m = x * (n + 1);
        p = (n + 1) << 1;
        
        for (int i = 0; i < d; ++i)
            for (int k = p; k >= 1; --k)
                for (int j = m; j >= a[i][0]; --j)
                    if (dp[j - a[i][0]][k - 1] != -1)
                        dp[j][k] = max(dp[j][k], dp[j - a[i][0]][k - 1] + a[i][1]);
                    
        for (int i = 0; i < d; ++i)
            for (int k = p; k >= 1; --k)
                for (int j = m; j >= a[i][0]; --j)
                    if (dp[j - a[i][0]][k - 1] != -1)
                        dp[j][k] = max(dp[j][k], dp[j - a[i][0]][k - 1] + a[i][1]);
                    
        int ma = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 1; j <= p; ++j) {
                int c = i * 11;
                if (c % 10 == 0)
                    c /= 10;
                else c = c / 10 + 1;
                
                if (c <= m) 
                    ma = max(ma, dp[i][j]);
            }
            
        printf("%.2f\n", ((double)ma / (double)(n + 1)));
    }
    
    return 0;
}
