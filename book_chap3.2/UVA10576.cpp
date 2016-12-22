#include <bits/stdc++.h>
using namespace std;

int s, d;

int main() {
    while (scanf("%d %d", &s, &d) != EOF) {
        int ma = -1;
        
        for (int i = 132; i < 4095; ++i) {
            bool work = true;
            
            for (int j = 0; j < 8 && work; ++j) {
                int c = 0;
                
                for (int k = 0; k < 5; ++k) {
                    if (i & 1 << (j + k)) 
                        c -= d;       
                    else c += s;
                }
                
                if (c > 0) {
                    work = false;
                    break;
                }
            }
            
            if (work) {
                int sum = 0;
                
                for (int j = 0; j < 12; ++j) {
                    if (i & 1 << j)
                        sum -= d;
                    else sum += s;
                }
                
                ma = max(ma, sum);
            }            
        }                        
        
        if (ma < 0)
            printf("Deficit\n");
        else printf("%d\n", ma);
    }
    
    return 0;
}
