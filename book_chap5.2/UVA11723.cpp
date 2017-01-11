#include <bits/stdc++.h>
using namespace std;

int n, r, k;

int main() {
    int c = 1;
    while (scanf("%d %d", &n, &r), n || r) {
        k = n / r;
        
        if (n % r == 0) {
            if (k <= 27)
                printf("Case %d: %d\n", c++, k - 1);
            else printf("Case %d: impossible\n", c++);
        } else {
            if (k > 26) {
                printf("Case %d: impossible\n", c++);
            } else {
                printf("Case %d: %d\n", c++, k);
            }
        }
    }
    
    return 0;
}
