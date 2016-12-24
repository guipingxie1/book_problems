#include <bits/stdc++.h>
using namespace std;

int n, m;
int d[20005];
int k[20005];

int main() {
    while (scanf("%d %d", &n, &m), n || m) {
        for (int i = 0; i < n; ++i)
            scanf("%d", d + i);
            
        for (int i = 0; i < m; ++i)
            scanf("%d", k + i);
        
        if (m < n) {
            printf("Loowater is doomed!\n");      
        } else {        
            sort(d, d + n);
            sort(k, k + m);
            
            int i = 0;
            int j = 0;
            
            int sum = 0;
            while (i != n && j != m) {
                if (k[j] >= d[i]) {
                    sum += k[j];
                    ++i;
                    ++j;
                } else {
                    ++j;
                }
            }
            
            if (i == n) 
                printf("%d\n", sum);
            else  printf("Loowater is doomed!\n");
        }
    }
    
    return 0;
}
