#include <bits/stdc++.h>
using namespace std;

bool v[1005][1005];
int n, m, x, y, r, c, k, xi, yi;
int a[] = {-1, 0, 1, 0};
int b[] = {0, 1, 0, -1};
pair<int, int> p;
int d[4];

int main() {
    while (scanf("%d %d", &n, &m), n || m) {
        memset(v, false, sizeof(v));
        scanf("%d", &x);
        for (int i = 0; i < x; ++i) {
            scanf("%d %d", &r, &c);
            
            for (int j = 0; j < c; ++j) {
                scanf("%d", &k);
                v[r][k] = true;
            }
        }
        
        scanf("%d %d %d %d", d, d + 1, d + 2, d + 3);
        int ans = -1;
        
        if (!(d[0] == d[2] && d[1] == d[3])) {            
            queue< pair<int, int> > q;
            q.push(make_pair(10000 * d[0] + d[1], 0));
            v[d[0]][d[1]] = true;
        
            while (!q.empty()) {
                p = q.front();
                q.pop();
                x = p.first / 10000;
                y = p.first % 10000;
                
                bool br = false;
                for (int i = 0; i < 4; ++i) {
                    xi = x + a[i];
                    yi = y + b[i];
                    
                    if (xi >= 0 && xi < n && yi >= 0 && yi < m && !v[xi][yi]) {
                        if (xi == d[2] && yi == d[3]) {
                            ans = p.second + 1;
                            br = true;
                            break;
                        } else {
                            v[xi][yi] = true;
                            q.push(make_pair(10000 * xi + yi, p.second + 1));
                        }
                    }
                }
                
                if (br)
                    break;
            }
        } else {
            ans = 0;
        }
        
        printf("%d\n", ans);
    }
    
    return 0;
}
