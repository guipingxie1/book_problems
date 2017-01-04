#include <bits/stdc++.h>
using namespace std;

int t, n, k;
long long a[100005];
long long d[100005];

int main() {
    scanf("%d", &t);
    
    for (int x = 1; x <= t; ++x) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%lld", a + i);
            
        long long c = 0;    
        for (int i = 0; i < n; ++i) {
            scanf("%d", &k);
            a[i] -= k;
            c += a[i];
        }
                
        printf("Case %d: ", x);
        if (c < 0) {
            printf("Not possible\n");
        } else {
            d[n - 1] = a[n - 1];
            for (int i = n - 2; i >= 0; --i)
                d[i] = min(a[i], a[i] + d[i + 1]);

            int idx = 0;
            for (int i = 0; i < n; ++i)
                if (d[i] >= 0) {
                    idx = i + 1;
                    break;
                }
                
            printf("Possible from station %d\n", idx);
        }        
    }
    
    return 0;
}
