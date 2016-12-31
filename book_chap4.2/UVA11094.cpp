#include <bits/stdc++.h>
using namespace std;

char c[22][22];
bool v[22][22];
int m, n, x, y, t, xi, yi;
int ai[] = {-1, 0, 1, 0};
int bi[] = {0, 1, 0, -1};

int main() {
    while (scanf("%d %d", &m, &n) != EOF) {
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                scanf(" %c", &c[i][j]);
                
        scanf("%d %d", &x, &y);
        char l = c[x][y];
        char o = (l + 256 - 1) % 256;
        
        memset(v, false, sizeof(v));
        
        queue<int> qi;
        qi.push(100 * x + y);        
        v[x][y] = true;
        c[x][y] = o;
        
        while (!qi.empty()) {
            t = qi.front();
            qi.pop();
            x = t / 100;
            y = t % 100;
            
            for (int i = 0; i < 4; ++i) {
                xi = x + ai[i];
                yi = (n + y + bi[i]) % n;
                
                if (xi >= 0 && xi < m && !v[xi][yi] && c[xi][yi] == l) {
                    v[xi][yi] = true;
                    c[xi][yi] = o;
                    qi.push(100 * xi + yi);
                }
            }
        }
        
        int ma = 0;
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j)
                if (c[i][j] == l) {
                    int co = 1;
                    
                    queue<int> q;
                    q.push(100 * i + j);        
                    v[i][j] = true;
                    c[i][j] = o;
                    
                    while (!q.empty()) {
                        t = q.front();
                        q.pop();
                        x = t / 100;
                        y = t % 100;
                        
                        for (int i = 0; i < 4; ++i) {
                            xi = x + ai[i];
                            yi = (n + y + bi[i]) % n;
                            
                            if (xi >= 0 && xi < m && !v[xi][yi] && c[xi][yi] == l) {
                                ++co;
                                v[xi][yi] = true;
                                c[xi][yi] = o;
                                q.push(100 * xi + yi);
                            }
                        }
                    }
                    
                    ma = max(ma, co);
                }
                
        printf("%d\n", ma);
    }
    
    return 0;
}
