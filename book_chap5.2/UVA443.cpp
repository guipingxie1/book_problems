#include <bits/stdc++.h>
using namespace std;

int a[5850];
int n, k, p, w, x, y, z, m;

int main() {
    w = 1;
    x = 1;
    y = 1;
    z = 1;
    a[1] = 1;
    
    for (int i = 2; i <= 5842; ++i) {
        m = min(min(2 * a[w], 3 * a[x]), min(5 * a[y], 7 * a[z]));
        
        if (2 * a[w] == m) 
            ++w;
        
        if (3 * a[x] == m) 
            ++x;
        
        if (5 * a[y] == m)
            ++y;
        
        if (7 * a[z] == m)
            ++z;
        
        a[i] = m;
    }
    
    while (scanf("%d", &n), n) {
        printf("The ");
        p = (n / 10) % 10;
        k = n % 10;
        
        if (k == 1) {
            if (p == 1)
                printf("%dth", n);
            else printf("%dst", n);
        } else if (k == 2) {
            if (p == 1)
                printf("%dth", n);
            else printf("%dnd", n);
        } else if (k == 3) {
            if (p == 1)
                printf("%dth", n);
            else printf("%drd", n);
        } else {
            printf("%dth", n);
        }
        
        printf(" humble number is %d.\n", a[n]);
    }
    
    return 0;
}
