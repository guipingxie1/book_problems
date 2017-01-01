#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, w;
priority_queue< pair<int, pair<int, int> > > pq;
pair<int, pair<int, int> > p;
vector<int> d;
int a[1005];

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
    while (scanf("%d %d", &n, &m), n || m) {
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d", &x, &y, &w);
            pq.push(make_pair(-1 * w,  make_pair(x, y)));
        }
        
        memset(a, -1, sizeof(a));
        
        int co = 1;
        while (co != n && !pq.empty()) {
            p = pq.top();
            pq.pop();
            
            if (uni(p.second.first, p.second.second)) 
                ++co;
            else d.push_back(-1 * p.first);
        }
        
        if (d.empty() && pq.empty()) {
            printf("forest\n");
        } else {
            while (!pq.empty()) {
                p = pq.top();
                pq.pop();      
                d.push_back(-1 * p.first);          
            }
                
            for (int i = 0; i < (int)d.size() - 1; ++i)
                printf("%d ", d[i]);
            printf("%d\n", d[(int)d.size() - 1]);
        }
        
        d.clear();
    }
    
    return 0;
}
