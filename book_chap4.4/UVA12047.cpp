#include <bits/stdc++.h>
using namespace std;

int t, n, m, u, v, p, x, y, w;
vector< pair<int, int> > a[10005];
vector< pair<int, int> > ra[10005];
map<int, int> ma;
pair< int, pair<int, int> > pp;
int d[10005];
int rd[10005];
int md[10005];
int mrd[10005];

int main() {
    scanf("%d", &t);
    
    while (t--) {
        scanf("%d %d %d %d %d", &n, &m, &u, &v, &p);
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d", &x, &y, &w);
            a[x].push_back(make_pair(y, w));
            ra[y].push_back(make_pair(x, w));
            ma[10005 * x + y] = w;
            ma[10005 * x + x] = 0;
            ma[10005 * y + y] = 0;
        }
        
        memset(d, -1, sizeof(d));
        memset(rd, -1, sizeof(rd));
        memset(md, -1, sizeof(md));
        memset(mrd, -1, sizeof(mrd));
        
        priority_queue< pair<int, pair<int, int> > > pq;
        pq.push(make_pair(0, make_pair(u, 0)));        
        
        while (!pq.empty()) {
            pp = pq.top();
            pq.pop();
            
            w = pp.first;
            x = pp.second.first;
            y = pp.second.second;
            
            if (d[x] == -1) {
                d[x] = -1 * w;
                md[x] = y;
                
                for (int i = 0; i < a[x].size(); ++i)
                    if (d[a[x][i].first] == -1) 
                        pq.push(make_pair(w - a[x][i].second, make_pair(a[x][i].first, max(y, a[x][i].second))));
            }
        }
        
        pq.push(make_pair(0, make_pair(v, 0)));        
        
        while (!pq.empty()) {
            pp = pq.top();
            pq.pop();
            
            w = pp.first;
            x = pp.second.first;
            y = pp.second.second;
            
            if (rd[x] == -1) {
                rd[x] = -1 * w;
                mrd[x] = y;
                
                for (int i = 0; i < ra[x].size(); ++i)
                    if (rd[ra[x][i].first] == -1) 
                        pq.push(make_pair(w - ra[x][i].second, make_pair(ra[x][i].first, max(y, ra[x][i].second))));
            }
        }
       
        int ans = -1;
        for (auto it = ma.begin(); it != ma.end(); ++it) {
            x = it -> first / 10005;
            y = it -> first % 10005;
            w = it -> second;
            
            if (d[x] != -1 && rd[y] != -1 && d[x] + rd[y] + w <= p)
                ans = max(ans, max(md[x], max(w, mrd[y])));
        }
        
        printf("%d\n", ans);
                
        for (int i = 1; i <= n; ++i) {
            a[i].clear();
            ra[i].clear();
        }
        
        ma.clear();
    }
    
    return 0;
}
