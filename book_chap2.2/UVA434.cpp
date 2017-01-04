#include <bits/stdc++.h>
using namespace std;

int t, n, m, e;
int a[10];
int b[10];
int c[10][10];
int ca[10];
int cb[10];

int main() {
    scanf("%d", &t);
    
    while (t--) {
        memset(c, 0, sizeof(c));
        memset(ca, 0, sizeof(ca));
        memset(cb, 0, sizeof(cb));
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
            ca[a[i]]++;
        }
            
        for (int i = 0; i < n; ++i) {
            scanf("%d", b + i);
            cb[b[i]]++;
        }            
            
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < n; ++j)
                if (b[j] == a[i])
                    c[i][j] = a[i];
        
        m = e = 0;        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                m += c[i][j];
                
        for (int i = 1; i <= 8; ++i) {
            if (ca[i]) {
                if (cb[i]) {
                    if (ca[i] > 1 && cb[i] > 1)
                        m -= (i * (ca[i] * cb[i] - max(ca[i], cb[i])));
                } else {
                    m += i * ca[i]; 
                }
            } else {
                if (cb[i])
                    m += i * cb[i];
            }
        }
           
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < n; ++j)
                c[i][j] = min(a[i], b[j]);
                
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                e += c[i][j];
                
        printf("Matty needs at least %d blocks, and can add at most %d extra blocks.\n", m, e - m);
    }
    
    return 0;
}
