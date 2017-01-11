#include <bits/stdc++.h>
using namespace std;

int t;
long long n;

int main() {
    scanf("%d", &t);
    
    for (int z = 1; z <= t; ++z) {
        scanf("%lld",  &n);
        
        if (n % 4 == 0 || n % 4 == 1)
            printf("Case %d: %lld\n", z, (n - 1) * n / 4);
        else printf("Case %d: %lld/2\n", z, (n - 1) * n / 2);
    }
    
    return 0;
}
