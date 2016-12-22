#include <bits/stdc++.h>
using namespace std;

int t, n, p;
int a[22];
bool b[1005];

int main() {
    scanf("%d", &t);
    
    while (t--) {
        scanf("%d %d", &n, &p);
        for (int i = 0; i < p; ++i)
            scanf("%d", a + i);
            
        if (n == 0) {
            printf("YES\n");
            continue;
        }
            
        memset(b, false, sizeof(b));
        b[0] = true;
            
        for (int i = 0; i < p; ++i) 
            for (int j = n; j >= a[i]; --j) 
                if (b[j - a[i]])
                    b[j] = true;
            
        if (b[n])
            printf("YES\n");
        else printf("NO\n");
    }
    
    return 0;
}
