#include <bits/stdc++.h>
using namespace std;

int t, n, x, y;
char c;
char a[12][12];
int xi[] = {1, 0, -1, 0};
int yi[] = {0, 1, 0, -1};

int main() {
    scanf("%d", &t);
    
    for (int z = 1; z <= t; ++z) {
        scanf("%d", &n);
        
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < n; ++j)
                scanf(" %c", &a[i][j]);
         
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (a[i][j] == '.') {
                    c = 'A';             
                
                    for (int l = 0; l < 4; ++l)
                        for (int k = 0; k < 4; ++k) {
                            x = i + xi[k];
                            y = j + yi[k];
                            
                            if (x >= 0 && x < n && y >= 0 && y < n)
                                if (a[x][y] == c)
                                    c = (char)(int)c + 1;                        
                        }       
                    
                    a[i][j] = c;         
                }                      
                
        printf("Case %d:\n", z);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                printf("%c", a[i][j]);
            printf("\n");
        }            
    }
    
    return 0;
}
