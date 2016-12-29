#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
    scanf("%d", &t);
    
    for (int x = 1; x <= t; ++x) {
        scanf("%d", &n);
        
        int a[n];
        int w[n];
        
        int in[n];
        int de[n];
        
        for (int i = 0; i < n; ++i)
            scanf("%d", a + i);
            
        for (int i = 0; i < n; ++i) {
            scanf("%d", w + i);
            in[i] = de[i] = w[i];
        }
        
        for (int i = 1; i < n; ++i) {
            int pin = in[i];
            int din = de[i];
            
            for (int j = 0; j < i; ++j) {
                if ((a[i] > a[j]) && (pin + in[j] > in[i]))
                    in[i] = pin + in[j];
                    
                if ((a[i] < a[j]) && (din + de[j] > de[i]))
                    de[i] = din + de[j];
            }
        }
        
        int inm = 0;
        int dem = 0;
        for (int i = 0; i < n; ++i) {
            inm = max(inm, in[i]);   
            dem = max(dem, de[i]);
        }
        
        printf("Case %d. ", x);
        if (inm >= dem)
            printf("Increasing (%d). Decreasing (%d).\n", inm, dem);
        else printf("Decreasing (%d). Increasing (%d).\n", dem, inm);
    }
    
    return 0;
}
