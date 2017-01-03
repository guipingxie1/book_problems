#include <bits/stdc++.h>
using namespace std;

int v[2005][2005];
int n, m, x, y, xi, yi;
pair<int, int> p;
int a[] = {-1, 0, 1, 0};
int b[] = {0, 1, 0, -1};

int main() {
    while(scanf("%d", &n), n) {
        memset(v, 0, sizeof(v));
        int mx = 0;
        int my = 0;
        int mix = 10000;
        int miy = 10000;
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &x, &y);
            v[x][y] = 2;   
            
            mx = max(mx, x);
            my = max(my, y);
            mix = min(mix, x);
            miy = min(miy, y);
        }
        
        bool equal = false;    
        scanf("%d", &m); 
        int mi = 100000;
        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &x, &y);
            if (v[x][y] == 2)
                equal = true;
                
            v[x][y] = 1;
            mx = max(mx, x);
            my = max(my, y);
            mix = min(mix, x);
            miy = min(miy, y);
        }
        
        priority_queue< pair<int, int> > q;
        q.push(make_pair(0, 10000 * x + y));
        v[x][y] = 3;
        
        if (!equal) {
            while(!q.empty()) {
                p = q.top();
                q.pop();
                x = p.second / 10000;
                y = p.second % 10000;
                
                bool br = false;
                for (int i = 0; i < 4; ++i) {
                    xi = x + a[i];
                    yi = y + b[i];
                    
                    if (xi >= mix && xi <= mx && yi >= miy && yi <= my) {
                        if (v[xi][yi] == 1) {
                            v[xi][yi] = 3;
                            q.push(make_pair(0, 10000 * xi + yi));
                        } else if (v[xi][yi] == 2) {
                            mi = -1 * (p.first - 1);
                            br = true;
                            break;
                        } else if (v[xi][yi] == 0) {
                            v[xi][yi] = 3;
                            q.push(make_pair(p.first - 1, 10000 * xi + yi));
                        }
                    }
                }
                
                if (br)
                    break;
            }
        } else {
            mi = 1;
        }
        
        printf("%d\n", mi);
    }
    
    return 0;
}
