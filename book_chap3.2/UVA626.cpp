#include <bits/stdc++.h>
using namespace std;

set< vector<int> > s;
vector<int> a[105];
int n, k;

void add(int x, int y, int z) {
    vector<int> v(3);
    
    if ((x > y && y > z) || (x < y && y < z)) {
        v[0] = x;
        v[1] = y;
        v[2] = z;
        
        s.insert(v);
    } 
}

int main() {
    while (scanf("%d", &n) == 1) {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) {
                scanf("%d", &k);
                
                if (k)
                    a[i].push_back(j);
            }
            
        int x, y, z;
        for (int i = 1; i <= n; ++i) {
            x = i;
            
            for (int j = 0; j < a[x].size(); ++j) {
                y = a[x][j];
                
                for (int k = 0; k < a[y].size(); ++k) {
                    z = a[y][k];
                    
                    auto it = find(a[z].begin(), a[z].end(), i);
                    
                    if (it != a[z].end())
                        add(x, y, z);
                }
            }
        }
        
        for (auto it = s.begin(); it != s.end(); ++it) 
            printf("%d %d %d\n", (*it)[0], (*it)[1], (*it)[2]);
        printf("total:%d\n\n", (int)s.size());
        
        s.clear();
        for (int i = 1; i <= n; ++i)
            a[i].clear();
    }
    
    return 0;
}
