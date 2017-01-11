#include <bits/stdc++.h>
using namespace std;

#define LOG 0.3010299956639812

int a[25];
int n, k;
double d, e;

int main() {
    a[2] = 3;
    a[3] = 5;
    a[4] = 8;
    
    d = log10(2) + log10(3) + log10(4) + log10(5) + log10(6) + log10(7) + log10(8);
    k = 9;
    
    for (int i = 5; i <= 22; ++i) {
        e = (1 << i) * LOG;
        while (e > d) {
            d += log10(k);
            ++k;
        }
        
        a[i] = k - 2;
    }

    while (scanf("%d", &n), n) {
        n /= 10;
        n -= 194;
        printf("%d\n", a[n]);
    }
    
    return 0;
}
