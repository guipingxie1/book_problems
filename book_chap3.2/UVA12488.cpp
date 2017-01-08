#include <bits/stdc++.h>
using namespace std;

int n, k;
int b[25];
int a[25];

int main() {
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; ++i) 
            scanf("%d", a + i);
        
        for (int i = 0; i < n; ++i)
            scanf("%d", b + i);
         
        int c = 0;    
        for (int i = 0; i < n; ++i) {
            bool f = false;
            int idx = 0;
            for (int j = i + 1; j < n && !f; ++j)
                if (b[i] == a[j]) {
                    f = true;
                    idx = j;
                }
            
            if (f) {
                c += idx - i;
                
                for (int j = idx; j > i; --j) 
                    a[j] = a[j - 1];
                a[i] = b[i];
            }
        }
            
        
        printf("%d\n", c);
    }
    
    return 0;
}
