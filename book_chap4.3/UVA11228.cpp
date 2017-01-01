#include <bits/stdc++.h>
using namespace std;

int t, n, r, k;
int c[1005][2];
int a[1005];
priority_queue< pair<int, pair<int, int> > > pq;
pair< int, pair<int, int> > p;
vector<int> dist;

int find(int v) {
    if (a[v] < 0)
        return v;
        
    return a[v] = find(a[v]);
}

bool uni(int x, int y) {
    int xx = find(x);
    int yy = find(y);
    
    if (xx == yy)
        return false;
      
    if (a[xx] >= a[yy]) {    
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
    
    for (int z = 1; z <= t; ++z) {
        scanf("%d %d", &n, &r);
        
        for (int i = 0; i < n; ++i) 
            scanf("%d %d", &c[i][0], &c[i][1]);
            
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j) {
                k = (c[i][0] - c[j][0]) * (c[i][0] - c[j][0]) + (c[i][1] - c[j][1]) * (c[i][1] - c[j][1]);
                pq.push(make_pair(-k, make_pair(i, j)));
            }    
            
        memset(a, -1, sizeof(a));
        
        int co = 1;
        while (co != n) {
            p = pq.top();
            pq.pop();
            
            if (uni(p.second.first, p.second.second)) {
                ++co;
                dist.push_back(-1 * p.first);   
            }
        }
        
        int state = 1;
        double ro = 0;
        double rr = 0;
        for (int i = 0; i < dist.size(); ++i) {
            if (dist[i] <= r * r) {
                ro += sqrt(dist[i]);
            } else {
                ++state;
                rr += sqrt(dist[i]);
            }
        }
        
        printf("Case #%d: %d %d %d\n", z, state, (int)round(ro), (int)round(rr));
        
        while (!pq.empty())
            pq.pop();
        dist.clear();    
    }
    
    return 0;
}   
