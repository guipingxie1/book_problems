#include <bits/stdc++.h>
using namespace std;

int n, m, c;

int main() {
    while (scanf("%d %d %d", &n, &m, &c), n) {
        n -= 7;
        m -= 7;
        
        if (n & 1 && m & 1 && c == 1)
            printf("%d\n", (n * m + 1) / 2);
        else printf("%d\n", (n * m) / 2);
    }
    
    return 0;
}
