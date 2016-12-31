#include <bits/stdc++.h>
using namespace std;

int n, m, k, si, sj, dir, pi, pj;
char a[105][105];
char c;

int main() {
    while (scanf("%d %d %d", &n, &m, &k), n || m || k) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                scanf(" %c", &a[i][j]);
                if (a[i][j] != '.' && a[i][j] != '*' && a[i][j] != '#') {
                    if (a[i][j] == 'N') {
                        dir = 0;
                    } else if (a[i][j] == 'S') {
                        dir = 2;
                    } else if (a[i][j] == 'L') {
                        dir = 1;
                    } else {
                        dir = 3;
                    } 
                    
                    si = i;
                    sj = j;
                    a[i][j] = '.';                   
                }
            }
        
        int co = 0;    
        for (int i = 0; i < k; ++i) {
            scanf(" %c", &c);
            if (c == 'F') {
                if (dir == 0) {
                    pi = si - 1;
                    
                    if (pi >= 0 && a[pi][sj] != '#') 
                        si = pi;
                } else if (dir == 1) {
                    pj = sj + 1;
                    
                    if (pj < m && a[si][pj] != '#') 
                        sj = pj;
                } else if (dir == 2) {
                    pi = si + 1;
                    
                    if (pi < n && a[pi][sj] != '#') 
                        si = pi;
                } else {
                    pj = sj - 1;
                    
                    if (pj >= 0 && a[si][pj] != '#') 
                        sj = pj;
                } 
                
                if (a[si][sj] == '*')
                    ++co;
                    
                a[si][sj] = '.';
            } else if (c == 'D') {
                dir = (dir + 1) % 4;
            } else {
                dir = (4 + dir - 1) % 4;
            }
        }
        
        printf("%d\n", co);
    }
    
    return 0;
}
