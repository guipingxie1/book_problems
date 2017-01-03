#include <bits/stdc++.h>
using namespace std;

int n, m, q, u, v;
int b[205];
int d[205];
vector< pair<int, int > > a[205];

int main() {
    int co = 1;
    while (scanf("%d", &n) == 1) {
        for (int i = 1; i <= n; ++i)
            scanf("%d", b + i);
            
        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &u, &v);
            a[u].push_back(make_pair(v, (b[v] - b[u]) * (b[v] - b[u]) * (b[v] - b[u])));
        }
        
        printf("Set #%d\n", co++);
        scanf("%d", &q);
        while (q--) {
            scanf("%d", &v);
            
            for (int i = 2; i <= n; ++i)
                d[i] = 10000000;
                
            d[1] = 0;
            for (int x = 1; x < n; ++x)
                for (int i = 1; i <= n; ++i)
                    if (d[i] != 10000000)
                        for (int j = 0; j < a[i].size(); ++j)
                            if (d[a[i][j].first] > d[i] + a[i][j].second)
                                d[a[i][j].first] = d[i] + a[i][j].second;
                   
            int ans = d[v];             
            bool neg = false;
            for (int x = 1; x < n; ++x)
                for (int i = 1; i <= n; ++i)
                    if (d[i] != 10000000)
                        for (int j = 0; j < a[i].size(); ++j)
                            if (d[a[i][j].first] > d[i] + a[i][j].second)
                                d[a[i][j].first] = d[i] + a[i][j].second;
                            
            if (d[v] < ans)
                neg = true;
                        
            if (neg || ans < 3 || ans == 10000000)
                printf("?\n");
            else printf("%d\n", ans);
        }
        
        for (int i = 1; i <= n; ++i)
            a[i].clear();
    }
    
    return 0;
}
