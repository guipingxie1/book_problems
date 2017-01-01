#include <bits/stdc++.h>
using namespace std;

int t, n, m, x, y, w;
priority_queue< pair<int, pair<int, int> > > pq;
pair<int, pair<int, int> > p;
vector< pair<int, int> > d;
vector< pair<int, pair<int, int> > > v;
int a[105];

int find(int i) {
    if (a[i] < 0)
        return i;
        
    return a[i] = find(a[i]);
}

bool uni(int x, int y) {
    int xx = find(x);
    int yy = find(y);
    
    if (xx == yy)
        return false;
      
    if (a[xx] <= a[yy]) {    
        a[xx] += a[yy];
        a[yy] = xx;
    } else {
        a[yy] += a[xx];
        a[xx] = yy;
    }   
    
    return true;
}

int main() {
    scanf("%d", &t);
    
    while (t--) {
        scanf("%d %d", &n, &m);
        
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d", &x, &y, &w);
            v.push_back(make_pair(-1 * w,  make_pair(x, y)));
            pq.push(v.back());
        }
        
        memset(a, -1, sizeof(a));
        
        int co = 1;
        int mst1 = 0;
        while (co != n && !pq.empty()) {
            p = pq.top();
            pq.pop();
            
            if (uni(p.second.first, p.second.second)) {
                ++co;
                mst1 -= p.first;
                d.push_back(p.second);
            }
        }
        
        printf("%d ", mst1);
        int mst_min2 = 1000000;
        for (int i = 1; i < n; ++i) {            
            int mst2 = 0;
            priority_queue< pair<int, pair<int, int> > > q;
            memset(a, -1, sizeof(a));
            
            for (int j = 0; j < v.size(); ++j)
                if (!(v[j].second.first == d[i - 1].first && v[j].second.second == d[i - 1].second))
                    q.push(v[j]);
            
            co = 1;
            while (co != n && !q.empty()) {
                p = q.top();
                q.pop();
                
                if (uni(p.second.first, p.second.second)) {
                    ++co;
                    mst2 -= p.first;
                }
            }
            
            if (co == n)
                mst_min2 = min(mst_min2, mst2);
        }
        
        printf("%d\n", mst_min2);
        
        d.clear();
        v.clear();
        while (!pq.empty())
            pq.pop();
    }
    
    return 0;
}
