#include <bits/stdc++.h>
using namespace std;

int t, r, c, m, n, w, x, y, e, o, co, temp, ti, tj;
bool a[105][105];
bool visited[105][105];

int main() {
    scanf("%d", &t);
    
    for (int z = 1; z <= t; ++z) {
        scanf("%d %d %d %d %d", &r, &c, &m, &n, &w);
        memset(a, false, sizeof(a));
        memset(visited, false, sizeof(visited));
        int di[] = {-m, -n, -n, -m, m, n, n, m};
        int dj[] = {-n, -m, m, n, n, m, -m, -n};
        
        while (w--) {
            scanf("%d %d", &x, &y);
            a[x][y] = true;
        }
        
        e = o = 0;
        
        visited[0][0] = true;
        queue<int> q;
        q.push(0);
        
        while (!q.empty()) {
            co = 0;
            temp = q.front();
            q.pop();
            
            x = temp / 1000;
            y = temp % 1000;
            set< pair<int, int> > s;
            
            for (int i = 0; i < 8; ++i) {
                ti = x + di[i];
                tj = y + dj[i];
                pair<int, int> p = make_pair(ti, tj);
                
                if (ti >= 0 && tj >= 0 && ti < r && tj < c && !a[ti][tj] && s.find(p) == s.end()) {
                    ++co;
                    s.insert(p);
                    
                    if (!visited[ti][tj]) {
                        visited[ti][tj] = true;
                        q.push(1000 * ti + tj);
                    }
                }
            }
            
            if (co & 1)
                ++o;
            else ++e;
        }
        
        printf("Case %d: %d %d\n", z, e, o);
    }
    
    return 0;
}
