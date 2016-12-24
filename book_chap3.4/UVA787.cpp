#include <bits/stdc++.h>
using namespace std;

int t, n;
int a[1005];

int main() {
    scanf("%d", &t);
    
    while (t--) {
        scanf("%d", &n);
        
        for (int i = 1; i <= n; ++i)
            scanf("%d", a + i);
            
        long long sum = 1;
        int co = 1;
        
        int idx = 2;
        while (idx < n) {
            if (sum + a[idx] < a[idx + 1]) {
                sum += a[idx];            
                ++co;
            }
            
            ++idx;
        }
        
        printf("%d\n", co + 1 /* from last element */);
    }
    
    return 0;
}
