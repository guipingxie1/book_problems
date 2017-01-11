#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
    while (scanf("%d", &n), n) {
        k = 0;
        printf("The parity of ");
        
        bool f = true;
        for (int i = 31; i >= 0; --i) {
            if (n & (1 << i)) {
                ++k;
                printf("1");
                f = false;
            } else {
                if (!f)
                    printf("0");
            }
        }
        
        printf(" is %d (mod 2).\n", k);
    }
    
    return 0;
}
