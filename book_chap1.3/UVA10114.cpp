#include <bits/stdc++.h>
using namespace std;

int main() {
    double d[105];
    int m, n, pre, i;
    double p, l, c, de;

    while(scanf("%d %lf %lf %d", &m, &p, &l, &n), m >= 0) {
        --n;
        scanf("%d %lf", &i, &de);
        d[0] = 1.0 - de;
        pre = 1;
        while (n--) {
            scanf("%d %lf", &i, &de);
            
            for (int j = pre; j < i; ++j)
                d[j] = d[j - 1];
            d[i] = 1.0 - de;
                
            pre = i + 1;
        }
        
        for (int j = pre; j <= m; ++j)
            d[j] = d[j - 1];            
        
        c = (l + p) * d[0];
        int mo = 0;
        double pay =  l / m;
        
        while (l >= c - 0.000001) {          
            ++mo;
            l -= pay;
            c *= d[mo];   
        } 
        
        if (mo == 1)
            printf("1 month\n");
        else printf("%d months\n", mo);
    }
     
    return 0;
}
