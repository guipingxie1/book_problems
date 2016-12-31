#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, t, k;
vector<int> a[10005];
int visit[10005];
int low[10005];
int high[10005];
int parent[10005];
set< pair<int, int> > sp;

void dfs(int t) {
    high[t] = low[t] = k;
    ++k;
    
    for (int j = 0; j < a[t].size(); ++j) {
        if (!visit[a[t][j]]) {
            visit[a[t][j]] = true;
            parent[a[t][j]] = t;
            dfs(a[t][j]);
            low[t] = min(low[t], low[a[t][j]]);
        } else if (a[t][j] != parent[t]) {
            low[t] = min(high[a[t][j]], low[t]);
        }
    }
}   

int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d (%d)", &x, &m);
            
            for (int j = 0; j < m; ++j) {
                scanf("%d", &y);
                a[x].push_back(y); 
            }
            
            visit[i] = false;
            low[i] = high[i] = parent[i] = 0;
        }
        
        int ans = 0;
        k = 0;
        
        for (int i = 0; i < n; ++i) 
            if (!visit[i]) {
                visit[i] = true;
                parent[i] = -1;
                dfs(i);
            }
                
        for (int i = 0; i < n; ++i) 
            if (parent[i] != -1) 
                if (low[i] > high[parent[i]])
                    sp.insert(make_pair(min(i, parent[i]), max(i, parent[i])));
                
        printf("%d critical links\n", (int)sp.size());
        for (auto it = sp.begin(); it != sp.end(); ++it)
            printf("%d - %d\n", (*it).first, (*it).second);
        printf("\n");
        
        for (int i = 0; i < n; ++i)
            a[i].clear();
        sp.clear();
    }
    
    return 0;
}
