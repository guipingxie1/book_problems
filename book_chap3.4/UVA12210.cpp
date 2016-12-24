#include <bits/stdc++.h>
using namespace std;

int m, f;
int a[10005];
int b[10005];

int main() {
    int c = 1;
    
    while (scanf("%d %d", &m, &f), m || f) {
        for (int i = 0; i < m; ++i)
            scanf("%d", a + i);
            
        for (int i = 0; i < f; ++i)
            scanf("%d", b + i);
            
        if (m <= f) {
            printf("Case %d: 0\n", c++);
        } else {
            int mi = 1 << 6;
            for (int i = 0; i < m; ++i)
                mi = min(mi, a[i]);
                
            printf("Case %d: %d %d\n", c++, m - f, mi);
        }
    }
    
    return 0;
}
