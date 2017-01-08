#include <bits/stdc++.h>
using namespace std;

#define esp 0.000001

int n;
double a[8];
int t[8][3];
bool b[65];

int main() {
    int c = 1;
    while (scanf("%d", &n), n != -1) {
        for (int i = 0; i < n; ++i)
            scanf("%lf %d %d %d", &a[i], &t[i][0], &t[i][1], &t[i][2]);
               
        memset(b, false, sizeof(b));
        for (int i = 30; i <= 60; ++i) {
            bool wo = true;
            
            for (int j = 0; j < n && wo; ++j) {
                double di = a[j] * 3600.0;
                double ti = di / (double)i;
                int g = t[j][0] + t[j][1];
                int r = t[j][2];
                
                int tii = ti;
                int k = tii % (g + r);
                if (k == g) {
                    double diff = ti - (double)tii;
                    if (diff > esp)
                        wo = false;
                } else if (k > g) {
                    wo = false;
                }
            }
            
            if (wo)
                b[i] = true; 
        }  
        
        printf("Case %d: ", c++);
        
        bool w = false;
        int idx = 30;
        int p = 30;
        bool f = true;
        while (idx != 61) {
            if (b[idx]) {
                p = idx;
                while (idx != 61 && b[idx + 1])
                    ++idx;
                
                w = true;
                    
                if (idx == p) {
                    if (f)
                        printf("%d", p);
                    else printf(", %d", p);
                } else {
                    if (f)
                        printf("%d-%d", p, idx);
                    else printf(", %d-%d", p, idx);
                }
                
                f = false;
            }
            
            ++idx;
        }  
        
        if (!w)
            printf("No acceptable speeds.");
        printf("\n");
    }
    
    return 0;
}
