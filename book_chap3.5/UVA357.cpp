#include <bits/stdc++.h>
using namespace std;

int n;
long long dp[30005][5];
int a[] = {1, 5, 10, 25, 50};

int main() {
    memset(dp, 0, sizeof(dp));
    
    for (int i = 0; i < 5; ++i)
        dp[0][i] = 1;
    
    for (int i = 1; i <= 30000; ++i)
        dp[i][0] = dp[i - 1][0];
        
    for (int i = 1; i < 5; ++i) 
        for (int j = 0; j <= 30000; ++j) {            
            dp[j][i] = dp[j][i - 1];
            
            if (j >= a[i])
                dp[j][i] += dp[j - a[i]][i];
        }        
 
    while (scanf("%d", &n) != EOF) {
        if (dp[n][4] == 1) 
            printf("There is only 1 way to produce %d cents change.\n", n);
        else printf("There are %lld ways to produce %d cents change.\n", dp[n][4], n);
    }
    
    return 0;
}
