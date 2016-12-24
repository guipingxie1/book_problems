#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
    while (scanf("%d", &n), n) {
        bool b = false;
        bool f = true;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &k);
            if (k) {
                if (f) {
                    printf("%d", k);
                    f = false;
                } else {
                    printf(" %d", k);                    
                }
                
                b = true;
            }
        }
            
        if (!b)
            printf("0");
        printf("\n");
    }    
    
    return 0;
}
