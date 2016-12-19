#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    scanf("%d", &t);
    
    while (t--) {
        scanf("%d", &n);
        
        int b[n][2];
        int price[n];
        for (int i = 0; i < n; ++i) 
            scanf("%d %d %d", &b[i][0], &b[i][1], &price[i]);
        
        if (n <= 5) {
            bool visit[25];
            memset(visit, false, sizeof(visit));
            for (int i = 0; i < n; ++i)
                visit[5 * b[i][0] + b[i][1]] = true;
                
            int extra = 5 - n;
            int count = 0;
            for (int i = 0; i < 25; ++i) {
                if (visit[i]) {              
                    printf("%d", i);
                    ++count;
                    if (count != 5) {
                        printf(" ");
                    } else {
                        printf("\n");
                        break;
                    }
                } else if (extra != 0) {
                    printf("%d", i);
                    --extra;
                    ++count;
                    if (count != 5) {
                        printf(" ");
                    } else {
                        printf("\n");
                        break;
                    }
                }
            }
        } else {           
            int c[n];
            int mi = 1000000000;
            for (int i = 0; i <= 20; ++i) 
                for (int j = i + 1; j <= 21; ++j) 
                    for (int k = j + 1; k <= 22; ++k) 
                        for (int l = k + 1; l <= 23; ++l) 
                            for (int m = l + 1; m <= 24; ++m) {
                                int sum = 0;
                                for (int o = 0; o < n; ++o) {
                                    int d = 1000000000;
                                    
                                    d = min(d, min(abs(b[o][0] - i / 5) + abs(b[o][1] - i % 5), min(abs(b[o][0] - j / 5) + abs(b[o][1] - j % 5), min(abs(b[o][0] - k / 5) + abs(b[o][1] - k % 5), min(abs(b[o][0] - l / 5) + abs(b[o][1] - l % 5), abs(b[o][0] - m / 5) + abs(b[o][1] - m % 5))))));
                                    sum += price[o] * d;
                                }           
                                
                                if (sum < mi) {
                                    mi = sum;
                                    c[0] = i;
                                    c[1] = j;
                                    c[2] = k;
                                    c[3] = l;
                                    c[4] = m;                                  
                                }                   
                            } 
                            
            for (int i = 0; i < 4; ++i)
                printf("%d ", c[i]);
            printf("%d\n", c[4]);                                           
        }
    }
    
    return 0;
}
