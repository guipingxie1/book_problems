#include <bits/stdc++.h>
using namespace std;

int t, n;
long long k, m, r, q, p;

long long pmod(long long a, long long b) {
    long long c = 1;
    
    while (b) {
        if (b & 1) {
            c *= a;
            c %= m;
        }
        
        b >>= 1;
        a *= a;
        a %= m;
    }
    
    return c % m;
}

int main() {
    scanf("%d", &t);
    
    for (int z = 1; z <= t; ++z) {
        scanf("%d %lld %lld", &n, &k, &m);
        
        q = k % m;
        q *= pmod(n, k - 1);
        q %= m;
        
        r = 0;        
        while (n--) {
            scanf("%lld", &p);
            p %= m;
            r += q * p;
            r %= m; 
        }
        
        printf("Case %d: %lld\n", z, r);
    }
    
    return 0;
}
