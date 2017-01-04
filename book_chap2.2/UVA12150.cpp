#include <bits/stdc++.h>
using namespace std;

int n, c, p, k;
int a[1005];

int main() {
    while (scanf("%d", &n), n) {
        memset(a, -1, sizeof(a));
        
        bool w = true;
        for (int i = 1; i <= n; ++i) {
            scanf("%d %d", &c, &p);
            k = i + p;
            
            if (k >= 1 && k <= n) {
                if (a[k] == -1)
                    a[k] = c;
                else w = false;
            } else {
                w = false;
            }
        }
        
        if (w) {
            for (int i = 1; i < n; ++i)
                printf("%d ", a[i]);
            printf("%d\n", a[n]);
        } else {
            printf("-1\n");
        }
    }
    
    return 0;
}
