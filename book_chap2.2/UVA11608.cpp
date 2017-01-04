#include <bits/stdc++.h>
using namespace std;

int n;
int a[12][2];
bool b[12];

int main() {
    int c = 1;
    while (scanf("%d", &n), n >= 0) {
        memset(b, false, sizeof(b));
        
        for (int i = 0; i < 12; ++i)
            scanf("%d", &a[i][0]);
            
        for (int i = 0; i < 12; ++i)
            scanf("%d", &a[i][1]);
        
        if (n >= a[0][1]) {
            n -= a[0][1];
            b[0] = true;
        }
        
        for (int i = 0; i < 11; ++i) {
            if (a[i][0] + n >= a[i + 1][1]) {
                b[i + 1] = true;
                n += (a[i][0] - a[i + 1][1]);
            } else {
                n += a[i][0];
            }
        }
        
        printf("Case %d:\n", c++);
        for (int i = 0; i < 12; ++i) {
            if (b[i])
                printf("No problem! :D\n");
            else printf("No problem. :(\n");
        }
    }
    
    return 0;
}
