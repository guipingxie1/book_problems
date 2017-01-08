#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    while (scanf("%d %d", &n, &m), n || m) {
        if (m >= n) {
            printf("0\n");
        } else {
            int l = n / m;
            
            bool w = false;
            for (int i = 1; i <= l && !w; ++i)
                if (n % (2 *  i + 1) == 0 && n / (2 * i + 1) == m)
                    w = true;
                
            if (!w) {
                double p = 0.0;
                double a = 0.0;
                int idx = 0;
                for (int i = 1; i <= l; ++i) {
                    a = i * i * ((double)n / i - m);
                    
                    if (a < p) {
                        idx = i - 1;
                        break;
                    }
                    
                    p = a;
                }
                
                printf("%d\n", idx);
            } else {
                printf("0\n");
            }
        }
    }
    
    return 0;
}
