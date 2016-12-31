#include <bits/stdc++.h>
using namespace std;

int t, n, m, x, y, xi, yi;
char c[105][105];
bool v[105][105];
int a[] = {-1, 0, 1, 0};
int b[] = {0, 1, 0, -1};

int main() {
    scanf("%d", &t);
    
    for (int z = 1; z <= t; ++z) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf(" %c", &c[i][j]);
                                
        int ans = 0;
        memset(v, false, sizeof(v));
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (c[i][j] == 'x' && !v[i][j]) {
                    ++ans;
                    queue<int> q;
                    q.push(i * 1000 + j);
                    v[i][j] = true;
                    
                    while (!q.empty()) {
                        m = q.front();
                        q.pop();
                        x = m / 1000;
                        y = m % 1000;
                        
                        for (int k = 0; k < 4; ++k) {
                            xi = x + a[k];
                            yi = y + b[k];
                            
                            if (xi >= 0 && xi < n && yi >= 0 && yi < n && !v[xi][yi] && c[xi][yi] != '.') {
                                v[xi][yi] = true;
                                q.push(1000 * xi + yi);
                            }
                        }
                    }
                }
        
        printf("Case %d: %d\n", z, ans);
    }
    
    return 0;
}
