#include <bits/stdc++.h>
using namespace std;

int t, n, k;
map<int, int> m;

int main() {
    scanf("%d", &t);
    
    for (int z = 1; z <= t; ++z) {
        scanf("%d", &n);
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                scanf("%d", &k);
                ++m[k];
            }
            
        bool w = true;
        
        for (auto it = m.begin(); it != m.end(); ++it)
            if (it -> second > n) {
                w = false;
                break;
            }
        
        if (w)
            printf("Case %d: yes\n", z);
        else printf("Case %d: no\n", z);
        
        m.clear();
    }
    
    return 0;
}
