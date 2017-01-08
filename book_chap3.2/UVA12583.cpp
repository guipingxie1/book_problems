#include <bits/stdc++.h>
using namespace std;

int t, n, k;
char c[505];
int b[26];

int main() {
    scanf("%d", &t);
    
    for (int z = 1; z <= t; ++z) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; ++i)
            scanf(" %c", c + i);
            
        memset(b, 0, sizeof(b));
        int ans = 0;
        int bo = min(k, n);
        for (int i = 0; i < bo; ++i) {
            ++b[c[i] - 'A'];
            
            if (b[c[i] - 'A'] > 1)
                ++ans;
        }
        
        for (int i = k; i < n; ++i) {
            ++b[c[i] - 'A'];            
            
            if (b[c[i] - 'A'] > 1)
               ++ans;
               
            --b[c[i - k] - 'A'];
        }
        
        printf("Case %d: %d\n", z, ans);
    }
    
    return 0;
}
