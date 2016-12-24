#include <bits/stdc++.h>
using namespace std;

int n, d, r;
int a[105];
int b[105];

int main() {
    while (scanf("%d %d %d", &n, &d, &r), n || d || r) {
        for (int i = 0; i < n; ++i)
            scanf("%d", a + i);
            
        for (int i = 0; i < n; ++i)
            scanf("%d", b + i);
            
        sort(a, a + n);
        sort(b, b + n);
        
        int sum = 0;
        for (int i = 0; i < n; ++i) 
            if (a[i] + b[n - 1 - i] > d) 
                sum += r * (a[i] + b[n - 1 - i] - d);
        
        printf("%d\n", sum);
    }
    
    return 0;
}
