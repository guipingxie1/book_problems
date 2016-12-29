#include <bits/stdc++.h>
using namespace std;

int n, m;
long long dp[205][205];

int main() {
    dp[0][0] = 1;
    for (int i = 1; i <= 200; ++i) {
        dp[i][0] = 1;
    
        for (int j = 1; j <= 200; ++j)
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 1000000;
    }

    while (scanf("%d %d", &n, &m), n || m) 
        printf("%lld\n", dp[n + m - 1][m - 1]);
    return 0;
}
