#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    while (scanf("%d %d", &n, &m), n || m) {
        int ans = 0;
        if ((n & 1) && (m & 1)) {
            if ((n == 1) || (m == 1)) 
                ans = n + m - 1;
            else ans = n * (m - 1) / 2 + (n + 1) / 2;
        } else {
            if ((n == 1) || (m == 1)) {
                ans = n + m - 1;
            } else if ((n == 2) || (m == 2)) {
                if ((n == 2) && (m == 2)) {
                    ans = 4;
                } else if (n == 2) {
                    if (m % 4 == 0) {
                        ans = 4 * (m / 4);
                    } else if (m % 4 == 1) {
                        ans = 4 * (m / 4) + 2;
                    } else {
                        ans = 4 * (1 + m / 4);
                    }
                } else {
                    if (n % 4 == 0) {
                        ans = 4 * (n / 4);
                    } else if (n % 4 == 1) {
                        ans = 4 * (n / 4) + 2;
                    } else {
                        ans = 4 * (1 + n / 4);
                    }
                }
            } else {
                ans = n * m / 2;
            }
        }
        
        printf("%d knights may be placed on a %d row %d column board.\n", ans, n, m);
    }
    
    return 0;
}
