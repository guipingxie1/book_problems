#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, z, k, co;
bool visit[2005];
int high[2005];
int low[2005];
vector<int> a[2005];
stack<int> st;

void SCC(int u) {
    high[u] = low[u] = ++k;
    visit[u] = true;
    st.push(u);
    
    for (int i = 0; i < a[u].size(); ++i) {
        if (!visit[a[u][i]])
            SCC(a[u][i]);
            
        if (visit[a[u][i]])
            low[u] = min(low[u], low[a[u][i]]);
    }
    
    if (low[u] == high[u])
        while (1) {
            x = st.top();
            st.pop();
            visit[x] = false;
            if (x == u)
                break;
        }
}

int main() {
    while (scanf("%d %d", &n, &m), n || m) {
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d", &x, &y, &z);
            if (z & 1) {
                a[x].push_back(y);
            } else {
                a[x].push_back(y);
                a[y].push_back(x);
            }
        }
        
        memset(visit, false, sizeof(visit));
        memset(high, 0, sizeof(high));
        memset(low, 0, sizeof(low));
        k = co = 0;
        
        for (int i = 1; i <= n; ++i)
            if (!visit[i])
                SCC(i);
        
        for (int i = 1; i <= n; ++i)
            if (high[i] == low[i])
                ++co;
        
        if (co == 1) 
            printf("1\n");
        else printf("0\n");
        
        for (int i = 1; i <= n; ++i)
            a[i].clear();
    }
    
    return 0;    
}
