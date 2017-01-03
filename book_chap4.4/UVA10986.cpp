#include <bits/stdc++.h>
using namespace std;

int t, n, m, s, e, x, y;
long long di;
vector< pair<long long, int> > a[20005];
bool v[20005];
pair<long long, int> p;

int main() {
    scanf("%d", &t);
    
    for (int z = 1; z <= t; ++z) {
        scanf("%d %d %d %d", &n, &m, &s, &e);
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %lld", &x, &y, &di);
            a[x].push_back(make_pair(di, y));
            a[y].push_back(make_pair(di, x));
        }
                
        long long mi = 10000000000;
                    
        memset(v, false, sizeof(v));
        priority_queue< pair<long long, int> > pq;
        pq.push(make_pair(0, s));
        
        while (!pq.empty()) {
            p = pq.top();
            pq.pop();
            
            y = p.second;
            di = p.first;
            
            if (!v[y]) {
                v[y] = true;
                
                if (y == e) {
                    mi = -1 * di;
                    break;
                }
                
                for (int i = 0; i < a[y].size(); ++i) {
                    if (!v[a[y][i].second])
                        pq.push(make_pair(di - a[y][i].first, a[y][i].second));
                }
            }
        }
        
        if (mi != 10000000000)
            printf("Case #%d: %lld\n", z, mi);
        else printf("Case #%d: unreachable\n", z);
        
        for (int i = 0; i < n; ++i)
            a[i].clear();
    }
    
    return 0;
}
