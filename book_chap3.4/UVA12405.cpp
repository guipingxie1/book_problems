#include <bits/stdc++.h>
using namespace std;

int t, n;
char c;
bool b;

int main() {
    scanf("%d", &t);
    
    for (int x = 1; x <= t; ++x) {
        scanf("%d", &n);
        int cont = 0;
        int co = 0;
        b = false;
        
        for (int i = 0; i < n; ++i) {
            scanf(" %c", &c);
            if (c == '.') {
                if (b) {
                    b = false;
                    continue;
                }
                
                ++cont;
                if (cont == 3) {
                    cont = 0;
                    ++co;
                }
            } else {                
                if (b)
                    b = false;
                    
                if (cont && cont < 3) {
                    ++co;
                    if (cont == 1) 
                        b = true;  
                }
                    
                cont = 0;
            }
        }
        
        if (cont && cont < 3)
            ++co;
        
        printf("Case %d: %d\n", x, co);
    }   
        
    return 0;
}
