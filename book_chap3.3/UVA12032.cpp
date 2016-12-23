#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];

bool works(int k) {
    if (a[0] == k)
        --k;
        
    for (int i = 1; i < n; ++i) {
        int d = a[i] - a[i - 1];
        if (d == k) {
            --k;
        } else if (d > k) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int t, c = 1;
    scanf("%d", &t);
    
    while (t--) {
        scanf("%d", &n);
        
        for (int i = 0; i < n; ++i)
            scanf("%d", a + i);
            
        int ma = a[0];
        int co = 1;
        for (int i = 1; i < n; ++i) {
            int d = a[i] - a[i - 1];
            if (d == ma) {
                ++co;
            } else if (d > ma) {
                ma = d;
                co = 1;
            }
        }
        
        if (co > 1) {
            printf("Case %d: %d\n", c++, 1 + ma); 
        } else {
            if (works(ma))
                printf("Case %d: %d\n", c++, ma); 
            else printf("Case %d: %d\n", c++, 1 + ma); 
        }
    }
    
    return 0;
}
