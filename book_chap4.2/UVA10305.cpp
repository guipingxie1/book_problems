#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, t;
int in[105];
vector<int> a[105];

int main() {
    while (scanf("%d %d", &n, &m), n || m) {
        memset(in, 0, sizeof(in));
        
        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &x, &y);
            ++in[y];
            a[x].push_back(y);
        }
        
        vector<int> ans;
        queue<int> q;
        for (int i = 1; i <= n; ++i) 
            if (in[i] == 0) {
                q.push(i);
                ans.push_back(i);
            }
            
        while (!q.empty()) {
            t = q.front();
            q.pop();
            
            for (int j = 0; j < a[t].size(); ++j) {
                --in[a[t][j]];
                
                if (in[a[t][j]] == 0) {
                    q.push(a[t][j]);
                    ans.push_back(a[t][j]);
                }
            }
        }
        
        for (int i = 0; i < (int)ans.size() - 1; ++i)
            printf("%d ", ans[i]);
        printf("%d\n", ans[(int)ans.size() - 1]);
        
        for (int i = 0; i < n; ++i)
            a[i].clear();
    }
    
    return 0;
}
