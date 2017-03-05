#include <bits/stdc++.h>
using namespace std;

int t, r, h, x, y, z, p;
int tp[25];
int rp[25];
int hp[25];

int tr[25][25];
int th[25][25];
int rh[25][25];

int main() {
    while (scanf("%d %d %d", &t, &r, &h) != -1) {
        p = 1000000000;
    
        for (int i = 0; i < t; ++i) {
            scanf("%d", &tp[i]);
            
            for (int j = 0; j < r; ++j)
                scanf("%d", &tr[i][j]);
        }
        
        for (int i = 0; i < r; ++i) {
            scanf("%d", &rp[i]);
            
            for (int j = 0; j < h; ++j)
                scanf("%d", &rh[i][j]);
        }
        
        for (int i = 0; i < h; ++i) {
            scanf("%d", &hp[i]);
            
            for (int j = 0; j < t; ++j)
                scanf("%d", &th[i][j]);
        }
        
        for (int i = 0; i < t; ++i)
            for (int j = 0; j < r; ++j)
                for (int k = 0; k < h; ++k)
                    if (!tr[i][j] && !rh[j][k] && !th[k][i])
                        if (tp[i] + rp[j] + hp[k] < p) {
                            p = tp[i] + rp[j] + hp[k];
                            x = i;
                            y = j;
                            z = k;
                        }
                        
        if (p != 1000000000)
            printf("%d %d %d:%d\n", x, y, z, p);
        else printf("Don't get married!\n");
    }
}
