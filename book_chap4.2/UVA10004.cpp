#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, t;
int c[205];
vector<int> a[205];

int main() {
    while (scanf("%d", &n), n) {
        scanf("%d", &m);
        while (m--) {
            scanf("%d %d", &x, &y);
            a[x].push_back(y);
            a[y].push_back(x);
        }
        
        memset(c, 0, sizeof(c));
        c[0] = 1;
        
        bool works = true;
        
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            t = q.front();
            q.pop();
            
            bool f = false;
            for (int i = 0; i < a[t].size(); ++i) {
                if (c[a[t][i]] == c[t]) {
                    f = true;
                    works = false;
                    break;
                } else if (c[a[t][i]] == 0) {
                    c[a[t][i]] = c[t] == 1 ? 2 : 1;
                    q.push(a[t][i]);
                }
            }
            
            if (f)
                break;
        }
        
        if (works)
            printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");
        
        for (int i = 0; i < n; ++i)
            a[i].clear();
    }
    
    return 0;
}
