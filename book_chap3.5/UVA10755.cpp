#include <bits/stdc++.h>
using namespace std;

int t, x, y, z;
long long a[21][21][21];
long long b[21];

long long kadane() {
    long long m = b[0];
    long long c = b[0];
    
    for (int i = 1; i < z; ++i) {
        c = max(b[i], c + b[i]);
        m = max(c, m);
    }
     
    return m;    
}

int main() {
    scanf("%d", &t);
    
    bool p = false;
    while (t--) {
        if (p)
            printf("\n");
            
        scanf("%d %d %d", &x, &y, &z);
        
        for (int i = 0; i < x; ++i)
            for (int j = 0; j < y; ++j)
                for (int k = 0; k < z; ++k) 
                    scanf("%lld", &a[i][j][k]); 
        
        long long m = -4000000000000000;
        
        for (int i = 0; i < x; ++i) 
            for (int j = i; j < x; ++j) 
                for (int k = 0; k < y; ++k) 
                    for (int l = k; l < y; ++l) {
                        for (int n = 0; n < z; ++n) 
                            b[n] = 0;
                        
                        for (int o = i; o <= j; ++o)
                            for (int q = k; q <= l; ++q) 
                                for (int n = 0; n < z; ++n) 
                                    b[n] += a[o][q][n];   
                            
                        m = max(m, kadane());    
                    }
        
        printf("%lld\n", m);
        p = true;
    }
    
    return 0;
}
