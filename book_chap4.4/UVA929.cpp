#include <bits/stdc++.h>
using namespace std;

int t, n, m, x, y, di, xi, yi;
int a[1000][1000];
bool v[1000][1000];
pair<int, int> p;

int b[] = {-1, 0, 1, 0};
int c[] = {0, 1, 0, -1};

int main() {
    scanf("%d", &t);
    
    while (t--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                scanf("%d", &a[i][j]);
                v[i][j] = false;
            }
        
        priority_queue< pair<int, int> > pq;
        pq.push(make_pair(0, 0));
        
        int ans = 0;
        
        while (!pq.empty()) {
            p = pq.top();
            pq.pop();
            
            x = p.second / 1000;
            y = p.second % 1000;
            di = p.first;
            
            if (!v[x][y]) {
                v[x][y] = true;
                
                if (x == n - 1 && y == m - 1) {
                    ans = di - a[x][y];
                    break;
                }
                
                for (int i = 0; i < 4; ++i) {
                    xi = x + b[i];
                    yi = y + c[i];
                    
                    if (xi >= 0 && xi < n && yi >= 0 && yi < m && !v[xi][yi]) 
                        pq.push(make_pair(di - a[x][y], 1000 * xi + yi));
                }
            }
        }
        
        printf("%d\n", -1 * ans);
    }
    
    return 0;
}
