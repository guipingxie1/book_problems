#include <bits/stdc++.h>
using namespace std;

int t, n, p;
int a[105];
bool b[3655];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &p);
        for (int i = 0; i < p; ++i)
            scanf("%d", a + i);
            
        memset(b, false, sizeof(b));
        for (int i = 1; i <= n; ++i) 
            if (i % 7 != 6 && i % 7 != 0) {
                bool w = false;
                
                for (int j = 0; j < p && !w; ++j)
                    if (i % a[j] == 0)
                        w = true;
                        
                b[i] = w; 
            }
        
        int c = 0;    
        for (int i = 1; i <= n; ++i) 
            if (b[i])
                ++c;
                
        printf("%d\n", c);
    }
    
    return 0;
}
