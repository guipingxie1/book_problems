#include <bits/stdc++.h>
using namespace std;

#define LOG 3.321928094887362348

int n, k, c, r, u;
double a, b, d, e, co;

int main() {
    while (scanf("%d", &n) == 1) {
        c = 0;
        a = log2(n);
        b = log2(n + 1);
        
        k = n;
        while (k) {
            ++c;
            k /= 10;
        }
        
        int i = c + 1;
        while (1) {
            d = a + i * LOG;
            r = d;
            
            if (d - r >= 0.49999999) {
                u = r + 1;
                
                e = b + i * LOG;
                if (e > u) {
                    printf("%d\n", u);
                    break;
                }   
            }
            
            ++i;
        }
    }
    
    return 0;
}
