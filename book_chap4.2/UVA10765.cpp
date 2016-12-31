#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, k;
bool visit[10005];
vector<int> a[10005];
int low[10005];
int high[10005];
int parent[10005];
set<int> s;

void dfs(int t) {
    int c = 0;
    low[t] = high[t] = ++k;
    
    for (int i = 0; i < a[t].size(); ++i) {
        if (!visit[a[t][i]]) {
            ++c;
            visit[a[t][i]] = true;
            parent[a[t][i]] = t;
            dfs(a[t][i]);
            low[t] = min(low[t], low[a[t][i]]);
            
            if (parent[t] != -1 && low[a[t][i]] >= high[t])
                s.insert(t);
        } else if (parent[t] != a[t][i]) {
            low[t] = min(low[t], high[a[t][i]]);
        }
    }
    
    if (parent[t] == -1 && c > 1)
        s.insert(t);
}

int main() {
    while (scanf("%d %d", &n, &m), n || m) {
        while (scanf("%d %d", &x, &y), x != -1 && y != -1) {
            a[x].push_back(y);
            a[y].push_back(x);
        }
        
        memset(low, 0, sizeof(low));
        memset(high, 0, sizeof(high));
        memset(parent, 0, sizeof(parent));
        memset(visit, false, sizeof(visit));
        
        k = 0;
        for (int i = 0; i < n; ++i)
            if (!visit[i]) {                
                visit[i] = true;
                parent[i] = -1;
                dfs(i);
            }
        
        priority_queue< pair<int, int> > pq;
        for (auto it = s.begin(); it != s.end(); ++it) {
            memset(visit, false, sizeof(visit));
            
            int c = 0;
            for (int i = 0; i < n; ++i)
                if (!visit[i] && i != *it) {
                    ++c;
                    queue<int> q;
                    q.push(i);
                    visit[i] = true;
                    
                    while (!q.empty()) {
                        k = q.front();
                        q.pop();
                        
                        for (int j = 0; j < a[k].size(); ++j) 
                            if (a[k][j] != *it && !visit[a[k][j]]) {
                                visit[a[k][j]] = true;
                                q.push(a[k][j]);
                            }
                    }
                }
                
            pq.push(make_pair(c, -1 * (*it)));
        }
        
        for (int i = 0; i < m; ++i) 
            if (s.find(i) == s.end())
                pq.push(make_pair(1, -1 * i));
        
        for (int i = 0; i < m; ++i) {
            pair<int, int> p = pq.top();
            pq.pop();
            printf("%d %d\n", -1 * p.second, p.first);
        }
        
        printf("\n");
        
        for (int i = 0; i < n; ++i)
            a[i].clear();
        s.clear();
    }
    
    return 0;
}
