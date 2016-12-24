#include <bits/stdc++.h>
using namespace std;

unsigned int n, l, u, m, x, y; 
bool b[32];

int main() {
    while (scanf("%d %d %d", &n, &l, &u) != EOF) {
        memset(b, false, sizeof(b));
        m = ~n;       
        for (int i = 0; i < 32; ++i)
            if (m & 1 << i)
                b[i] = true;
               
        y = 0;        
        bool add = false;
        for (int i = 31; i >= 0; --i) {
            if (l & 1 << i) {
                if ((!add && !b[i]) || (b[i] && ((y | (1 << i)) <= u))) 
                    y |= 1 << i;
            } else if (b[i] && ((y | (1 << i)) <= u)) {
                y |= 1 << i;
                add = true;
            }
        }
            
        printf("%u\n", y);
    }
    
    return 0;
}
