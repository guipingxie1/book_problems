#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
    scanf("%d", &t);
        
    while (t--) {
        scanf("%d", &n);
        
        if (n == 1)
            printf("0.000\n");
        else printf("%.3f\n", (n - 1) * 4 + (n - 2) * (n - 2) * sqrt(2));
        
        if (t)
            printf("\n");
    }
    
    return 0;
}
