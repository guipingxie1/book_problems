#include <bits/stdc++.h>
using namespace std;

int n, k, d, t, s, c;
int a[1005];

int main() {
    while (scanf("%d", &n), n) {
        s = c = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d.%d", &k, &d);
            t = 100 * k + d;
            a[i] = t;
            s += t;
        }
        
        k = s % n;
        s /= n;
        sort(a, a + n);
        
        t = n - 1;
        
        while (k--) 
            c += abs(s + 1 - a[t--]);
                    
        while (t != -1)
            c += abs(s - a[t--]);
        
        c /= 2;
        printf("$%d.%02d\n", c / 100, c % 100);
    }    
    
    return 0;
}
