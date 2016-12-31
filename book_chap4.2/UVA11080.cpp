#include <bits/stdc++.h>
using namespace std;

int t, v, e, x, y, k;
int c[205];
vector<int> a[205];

int main() {
    scanf("%d", &t);
    
    while (t--) {
        scanf("%d %d", &v, &e);
        for (int i = 0; i < e; ++i) {
            scanf("%d %d", &x, &y);
            a[x].push_back(y);
            a[y].push_back(x);
        }
            
        memset(c, 0, sizeof(c));
        
        int mi = 0;
        bool works = true;
        
        for (int i = 0; i < v && works; ++i) 
            if (c[i] == 0) {
                c[i] = 1;
                queue<int> q;
                q.push(i);
                int ee = 0;
                int oo = 1;
                
                while (!q.empty()) {
                    k = q.front();
                    q.pop();
                    
                    bool b = false;
                    for (int j = 0; j < a[k].size(); ++j) {
                        if (c[a[k][j]] == c[k]) {
                            b = true;
                            works = false;
                            break;
                        } else if (c[a[k][j]] == 0) {
                            if (c[k] == 1) {
                                ++ee;
                                c[a[k][j]] = 2;
                            } else {
                                ++oo;
                                c[a[k][j]] = 1;
                            }
                            
                            q.push(a[k][j]);
                        }
                    }
                    
                    if (b)
                        break;
                }
                
                mi += max(1, min(ee, oo));
            }
        
        if (works) 
            printf("%d\n", mi);
        else printf("-1\n");
        
        for (int i = 0; i < v; ++i)
            a[i].clear();
    }
    
    return 0;
}
