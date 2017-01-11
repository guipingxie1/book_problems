#include <bits/stdc++.h>
using namespace std;

long long n;
int k;

bool solve(long long p) {
    for (int i = 9; i >= 2; --i) {
        long long co = p;
        bool w = true;
        for (int j = 0; j < i && w; ++j) {
            if (co % i != 1) {
                w = false;
                break;
            } else {
                co = (co - 1) / i;
                co *= (i - 1);
            }
        }
        
        if (w && co % i == 0) {
            k = i;
            return true;
        }
    }
    
    return false;
}

int main() {
    while (scanf("%lld", &n), n >= 0) {
        printf("%lld coconuts, ", n);
        
        if (solve(n))
            printf("%d people and 1 monkey\n", k);
        else printf("no solution\n");
    }
    
    return 0;
}
