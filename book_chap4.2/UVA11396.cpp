#include <bits/stdc++.h>
using namespace std;

int n, x, y, t;
vector<int> a[305];
int c[305];

int main() {
    while (scanf("%d", &n), n) {
        while (scanf("%d %d", &x, &y), x || y) {
            a[x].push_back(y);
            a[y].push_back(x);
        }

        memset(c, 0, sizeof(c));
        
        bool w = true;
        for (int i = 1; i <= n && w; ++i) 
            if (c[i] == 0) {
                c[i] = 1;
                queue<int> q;
                q.push(i);
                
                while (!q.empty()) {
                    t = q.front();
                    q.pop();
                    
                    bool b = true;
                    for (int j = 0; j < a[t].size(); ++j) {
                        if (c[a[t][j]] == c[t]) {
                            w = false;
                            b = false;
                            break;
                        } else if (c[a[t][j]] == 0) {
                            c[a[t][j]] = c[t] == 1 ? 2 : 1;
                            q.push(a[t][j]);
                        }
                    }
                    
                    if (!b)
                        break;
                }
            }
            
        if (w)
            printf("YES\n");
        else printf("NO\n");
        
        for (int i = 1; i <= n; ++i)
            a[i].clear();
    }
    
    return 0;    
}
