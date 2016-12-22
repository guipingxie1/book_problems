#include <bits/stdc++.h>
using namespace std;

int n;
bool in[12][7];
bool t[10][7] = {{1,1,1,1,1,1,0}, {0,1,1,0,0,0,0}, {1,1,0,1,1,0,1}, {1,1,1,1,0,0,1}, {0,1,1,0,0,1,1}, {1,0,1,1,0,1,1}, {1,0,1,1,1,1,1}, {1,1,1,0,0,0,0}, {1,1,1,1,1,1,1}, {1,1,1,1,0,1,1}};

bool solve() {
    for (int i = 9; i >= n - 1; --i) {
        int work = true;
        int j = 0;
        
        for (int k = 0; k < n && work; ++k) {
            for (int x = 0; x < 7; ++x) {
                if (in[k][x] && (j & 1 << x) || (!t[i - k][x] && in[k][x])) {
                    work = false;
                    break;
                } 
                
                if (!(j & 1 << x)) 
                    if (t[i - k][x] && !in[k][x])
                        j |= 1 << x;                    
            }
        }
        
        if (work) 
            return true;
    }
    
    return false;
}

int main() {
    char c;
    while (scanf("%d", &n), n) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < 7; ++j) {
                scanf(" %c", &c);
                if (c == 'Y')
                    in[i][j] = 1;
                else in[i][j] = 0;
            }
        
        /*        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 7; ++j)
                printf("%c", in[i][j]);
            printf("\n");       
        } 
        */
        
        if (solve())
            printf("MATCH\n");
        else printf("MISMATCH\n");
    }
        
    return 0;
}
