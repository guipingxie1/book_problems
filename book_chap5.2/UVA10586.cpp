#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[10005];

int main() {
    while (scanf("%d %d", &n, &k), n != -1) {
        for (int i = n; i >= 0; --i)
            scanf("%d", a + i);
            
        int idx = 0;
        
        while (n - idx >= k) {
            a[idx + k] -= a[idx];
            ++idx;
        }
        
        if (k == 0)
            a[idx] = 0;
        
        for (int i = n; i > idx; --i)
            printf("%d ", a[i]);
        printf("%d\n", a[idx]);
    }
    
    return 0;
}
