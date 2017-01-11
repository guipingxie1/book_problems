#include <bits/stdc++.h>
using namespace std;

int n, m, k, l, u;

void solve() {
    m = n << 1;
    int s = sqrt(m);
    
    for (int i = s; i; --i) {
        if (m % i == 0) {
            k = i + m / i;
            
            if (k & 1) {
                u = (k - 1) / 2;
                l = u - i + 1; 
                printf("%d = %d + ... + %d\n", n, l, u);
                return;
            } 
        }
    }
}

int main() {
    while (scanf("%d", &n), n != -1)
        solve();    
    
    return 0;
}
