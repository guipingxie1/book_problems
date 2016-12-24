#include <bits/stdc++.h>
using namespace std;

int n;
int a[10005];
vector<int> s[10005];

int main() {
    bool b = false;
    while (scanf("%d", &n), n) {
        if (b)            
            printf("\n");
            
        for (int i = 0; i < n; ++i)
            scanf("%d", a + i);
            
        sort(a, a + n);
            
        int ma = 1;
        int co = 1;
        for (int i = 1; i < n; ++i) {
            if (a[i] == a[i - 1]) {
                ++co;
            } else {
                ma = max(ma, co);       
                co = 1;
            }
        }
        
        ma = max(ma, co);
        
        int mc = 0;
        if (n % ma == 0)
            mc = n / ma;
        else mc = n / ma + 1;
        
        int idx = 1;
        s[0].push_back(a[0]);
        for (int i = 1; i < n; ++i) {
            if (idx == ma)
                idx = 0;
                
            s[idx].push_back(a[i]);
            ++idx;
        }
        
        printf("%d\n", ma);
        for (int i = 0; i < ma; ++i) {
            for (int j = 0; j < (int)s[i].size() - 1; ++j)
                printf("%d ", s[i][j]);
            printf("%d\n", s[i][(int)s[i].size() - 1]);
        }
        
        b = true;
        
        for (int i = 0; i < ma; ++i)
            s[i].clear();
    }   
    
    return 0;
}
