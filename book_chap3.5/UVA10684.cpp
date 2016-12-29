#include <bits/stdc++.h>
using namespace std;

int n;
int a[10005];

int main() {
    while (scanf("%d", &n), n) {
        for (int i = 0; i < n; ++i)
            scanf("%d", a + i);
            
        int m = a[0];
        int c = a[0];
        
        for (int i = 1; i < n; ++i) {
            c = max(a[i], c + a[i]);
            m = max(m, c);
        }
        
        if (m <= 0)
            printf("Losing streak.\n");
        else printf("The maximum winning streak is %d.\n", m);
    }
    
    return 0;
}
