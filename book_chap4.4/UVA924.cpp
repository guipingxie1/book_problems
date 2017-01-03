#include <bits/stdc++.h>
using namespace std;

int n, m, k, t;
vector<int> a[2505];
bool v[2505];
int day[2505];
pair<int, int> p;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &m);
        
        for (int j = 0; j < m; ++j) {
            scanf("%d", &k);
            a[i].push_back(k);  
        }
    }
    
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &k);
        memset(v, false, sizeof(v));
        
        if (a[k].empty()) {
            printf("0\n");
        } else {
            queue< pair<int, int> > q;
            v[k] = true;
            q.push(make_pair(k, 0));
            int max_day;
            memset(day, 0, sizeof(day));
        
            while (!q.empty()) {
                p = q.front();
                q.pop();
                int c = 0;
                
                for (int i = 0; i < a[p.first].size(); ++i)
                    if (!v[a[p.first][i]]) {
                        ++c;
                        v[a[p.first][i]] = true;
                        q.push(make_pair(a[p.first][i], p.second + 1));
                    }
                    
                day[p.second + 1] += c;
                max_day = p.second + 1;
            }
            
            int idx = 0;
            for (int i = 1; i <= max_day; ++i)
                if (day[i] > day[idx])
                    idx = i;
            
            printf("%d %d\n", day[idx], idx);
        }
    }    
    
    return 0;
}
