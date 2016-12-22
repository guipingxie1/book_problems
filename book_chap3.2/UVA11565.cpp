#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, a, b, c;
    scanf("%d", &t);
    
    while(t--) {
        scanf("%d %d %d", &a, &b, &c);
        bool found = false;
        int first_bound = min(a / 3, min((int)cbrt(b), (int)sqrt(c / 3)));
        
        for (int i = -100; i <= 98 && !found; ++i)
            for (int j = i + 1; j <= 99 && !found; ++j) {
                int k = a - i - j;
                if (j < k && i * j * k == b && i * i + j * j + k * k == c) {
                    found = true;
                    printf("%d %d %d\n", i, j, k);
                }
            }
        
        if (!found)
            printf("No solution.\n");
    }
    
    return 0;
}
