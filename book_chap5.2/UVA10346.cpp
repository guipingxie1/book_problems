#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
    while (scanf("%d %d", &n, &k) != EOF) {
        int c = n;        
        int r = n;
        
        while (r >= k) {
            c += r / k;
            r -= (r / k) * k - r / k;
        }
        
        printf("%d\n", c);
    }
    
    return 0;
}
