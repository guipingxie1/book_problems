#include <bits/stdc++.h>
using namespace std;

int n, c, p;

int main() {
    while (scanf("%d", &n), n) {
        p = 1;
        c = 0;
        
        while (p < n) {
            ++c;
            p <<= 1;
        }
        
        if (p == n)
            printf("%d\n", n);
        else printf("%d\n", (n - (p >> 1)) << 1);        
    }
    
    return 0;
}
