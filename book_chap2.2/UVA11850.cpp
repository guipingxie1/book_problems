#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[1425];

int main() {
    while (scanf("%d", &n), n) {
        for (int i = 0; i < n; ++i)
            scanf("%d", a + i);
        
        sort(a, a + n);
        
        bool w = true;
            
        for (int i = 1; i < n && w; ++i)
            if (200 < a[i] - a[i - 1]) 
                w = false;
        
        if (w) 
            if (200 < 2 * (1422 - a[n - 1])) 
                w = false;
        
        if (w)
            printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");
    }
    
    return 0;
}
