#include <bits/stdc++.h>
using namespace std;

int t, n;
int a[12];

int main() {
    scanf("%d", &t);
    
    for (int z = 1; z <= t; ++z) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", a + i);
            
        sort(a, a + n);
        printf("Case %d: %d\n", z, a[n / 2]);
    }
    
    return 0;
}
