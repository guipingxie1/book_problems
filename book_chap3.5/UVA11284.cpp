#include <bits/stdc++.h>
using namespace std;

int t, n, m, p, x, y, s;
long long in, de;

long long d[52][52];
vector<int> v;
long long dp[15][2050];
long long a[52];

long long tsp(int curr, int k) {
    if (k == (1 << (p + 1)) - 1)
        return a[v[curr]] - d[v[curr]][0];
        
    if (dp[curr][k] != -1)
        return dp[curr][k];
    
    // Go home early
    long long ans = a[v[curr]] - d[v[curr]][0]; 
    for (int i = 1; i <= p; ++i)
        if (!(k & 1 << i))
            if (d[v[curr]][v[i]] != -1) 
                ans = max(ans, a[v[curr]] - d[v[curr]][v[i]] + tsp(i, k | (1 << i)));   
        
    return dp[curr][k] = ans;
}

int main() {
    scanf("%d", &t);
    
    while (t--) {
        scanf("%d %d", &n, &m);
        memset(d, -1, sizeof(d));
        memset(dp, -1, sizeof(dp));
        memset(a, 0, sizeof(a));
        
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %lld.%lld", &x, &y, &in, &de);
            
            if (d[x][y] != -1)
                d[x][y] = d[y][x] = min(100 * in + de, d[x][y]);  
            else d[x][y] = d[y][x] = 100 * in + de;     
        }
        
        // Home
        v.push_back(0);
        
        scanf("%d", &p);
        for (int i = 0; i < p; ++i) {
            scanf("%d %lld.%lld", &s, &in, &de);            
            a[s] += 100 * in + de;
        }
        
        for (int i = 0; i <= n; ++i)
            if (a[i])
                v.push_back(i);
        
        for (int i = 0; i <= n; ++i)
            d[i][i] = 0;
            
        for (int k = 0; k <= n; ++k)
            for (int i = 0; i <= n; ++i)
                for (int j = 0; j <= n; ++j)
                    if (d[i][k] != -1 && d[k][j] != -1) {
                        if (d[i][j] != -1)
                            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                        else d[i][j] = d[i][k] + d[k][j];
                    }
        
        // Start at home
        long long ans = tsp(0, 1 << 0);
        
        if (ans <= 0)
            printf("Don't leave the house\n");
        else printf("Daniel can save $%lld.%02lld\n", ans / 100, ans % 100);

        v.clear();
    }
    
    return 0;
}
