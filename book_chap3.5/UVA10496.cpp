#include <bits/stdc++.h>
using namespace std;

int t, x, y, n;
int a[12][2];
int dp[12][2050];

int dist(int i, int j) {
    return abs(a[i][0] - a[j][0]) + abs(a[i][1] - a[j][1]);
}

int tsp(int curr, int k) {
    if (k == (1 << (n + 1)) - 1)
        return dist(curr, 0);
        
    if (dp[curr][k] >= 0)
        return dp[curr][k];
        
    int mi = 1000000;    
    for (int i = 1; i <= n; ++i)
        if (!(k & 1 << i))
            mi = min(mi, dist(curr, i) + tsp(i, k | (1 << i)));
            
    return dp[curr][k] = mi;
}

int main() {
    scanf("%d", &t);
    
    while (t--) {
        scanf("%d %d %d %d %d", &x, &y, &a[0][0], &a[0][1], &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d %d", &a[i][0], &a[i][1]);
            
        memset(dp, -1, sizeof(dp));
        printf("The shortest path has length %d\n", tsp(0, 1 << 0));
    }
    
    return 0;
}
