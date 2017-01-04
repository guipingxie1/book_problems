#include <bits/stdc++.h>
using namespace std;

int t, m, n;
set<int> b[3];
set<int> c[3];

int main() {
    scanf("%d", &t);
    
    for (int x = 1; x <= t; ++x) {
        for (int j = 0; j < 3; ++j) {
            scanf("%d", &n);
            
            for (int i = 0; i < n; ++i) {
                scanf("%d", &m);
                b[j].insert(m);
            }
        }
        
        for (int i = 0; i < 3; ++i)
            for (auto it = b[i].begin(); it != b[i].end(); ++it) {
                if (i == 0) {
                    if (b[1].find(*it) == b[1].end() && b[2].find(*it) == b[2].end())
                        c[0].insert(*it);
                } else if (i == 1) {
                    if (b[0].find(*it) == b[0].end() && b[2].find(*it) == b[2].end())
                        c[1].insert(*it);
                } else {
                    if (b[1].find(*it) == b[1].end() && b[0].find(*it) == b[0].end())
                        c[2].insert(*it);
                }
            }
        
        int mi = 0;
        mi = max(mi, max((int)c[0].size(), max((int)c[1].size(), (int)c[2].size())));
        printf("Case #%d:\n", x);
        
        for (int i = 0; i < 3; ++i)
            if (c[i].size() == mi) {
                printf("%d %d", i + 1, (int)c[i].size());
                
                for (auto it = c[i].begin(); it != c[i].end(); ++it)
                    printf(" %d", *it);
                printf("\n");
            }
            
        for (int i = 0; i < 3; ++i) {
            b[i].clear();
            c[i].clear();
        }
    }
    
    return 0;
}
