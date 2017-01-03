#include <bits/stdc++.h>
using namespace std;

int t, n, e, ti, m, di, x, y;
vector< pair<int, int> > a[105];
bool v[105];
pair<int, int> p;

int main() {
    scanf("%d", &t);
    
    bool f = true;
    while (t--) {
        if (!f)
            printf("\n");
            
        scanf("%d %d %d %d", &n, &e, &ti, &m);
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d", &x, &y, &di);
            a[x].push_back(make_pair(di, y));
        }
                
        int ans = 0;
            
        for (int x = 1; x <= n; ++x) {
            memset(v, false, sizeof(v));
            priority_queue< pair<int, int> > pq;
            pq.push(make_pair(0, x));
            
            while (!pq.empty()) {
                p = pq.top();
                pq.pop();
                
                y = p.second;
                di = p.first;
                
                if (!v[y]) {
                    v[y] = true;
                    
                    if (y == e) {
                        if (abs(di) <= ti)
                            ++ans;
                        break;
                    }
                    
                    for (int i = 0; i < a[y].size(); ++i) {
                        if (!v[a[y][i].second])
                            pq.push(make_pair(di - a[y][i].first, a[y][i].second));
                    }
                }
            }
        }
        
        printf("%d\n", ans);
        
        for (int i = 1; i <= n; ++i)
            a[i].clear();
        f = false;
    }
    
    return 0;
}
