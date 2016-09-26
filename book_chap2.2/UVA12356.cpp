#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, x, y;
    while (scanf("%d %d", &n, &m), n || m) {
        int a[n + 1];
        int b[n + 1];
        for (int i = 2; i < n; ++i) {
            a[i] = i - 1;
            b[i] = i + 1;
        }

        a[1] = b[n] = 0; 

        if (n > 1) {
            b[1] = 2;
            a[n] = n - 1;
        } 

        while (m--) {
            scanf("%d %d", &x, &y);
            b[a[x]] = b[y];
            a[b[y]] = a[x];

            if (a[x] == 0) 
                printf("* "); 
            else printf("%d ", a[x]);
            
            if (b[y] == 0) 
                printf("*\n"); 
            else printf("%d\n", b[y]);
        }

        printf("-\n");
    }

    return 0;
}
