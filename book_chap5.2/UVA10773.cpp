#include <bits/stdc++.h>
using namespace std;

int t, d, u, v;

int main() {
    scanf("%d", &t);
    
    for (int z = 1; z <= t; ++z) {
        scanf("%d %d %d", &d, &v, &u);
        
        if (v >= u || v == 0)
            printf("Case %d: can't determine\n", z);
        else printf("Case %d: %.3lf\n", z, d / sqrt(u * u - v * v) - (double)d / u);
    }
    
    return 0;
}
