#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int a[45][2];
int dp[305][305];

int main() {
    scanf("%d", &t);
    
    while (t--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; ++i)
            scanf("%d %d", &a[i][0], &a[i][1]);
            
        for (int i = 0; i <= m; ++i)
            for (int j = 0; j <= m; ++j)
                dp[i][j] = 10000;
                
        dp[0][0] = 0;
        
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j <= m - a[i][0]; ++j)
                for (int k = 0; k <= m - a[i][1]; ++k)
                    if (dp[j][k] != 10000)                                            
                        dp[j + a[i][0]][k + a[i][1]] = min(dp[j + a[i][0]][k + a[i][1]], 1 + dp[j][k]);
                        
        int mi = 10000;
        for (int i = 0; i <= m; ++i)
            for (int j = 0; j <= m; ++j)
                if (i * i + j * j == m * m)
                    mi = min(mi, dp[i][j]);
                    
        if (mi == 10000)
            printf("not possible\n");
        else printf("%d\n", mi);        
    }
    
    return 0;
}
