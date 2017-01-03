#include <bits/stdc++.h>
using namespace std;

int a[62505];
int b[62505];

int n, m, t, len1, len2;

int main() {
    scanf("%d", &t);
    
    for (int x = 1; x <= t; ++x) {
        scanf("%d %d %d", &n, &len1, &len2);
        
        memset(a, -1, sizeof(a));
        for (int i = 0; i <= len1; ++i) {
            scanf("%d", &m);
            a[m] = i;
        }
            
        int k = 0;
        for (int i = 0; i <= len2; ++i) {
            scanf("%d", &m);        
            if (a[m] != -1)
                b[k++] = a[m];
        }
        
        vector<int> v;
        v.push_back(b[0]);
        int j = 0;
        for (int i = 1; i < k; ++i) {
            j = lower_bound(v.begin(), v.end(), b[i]) - v.begin();
            
            if (j == v.size()) 
                v.push_back(b[i]);
            else v[j] = b[i];
        }
            
        printf("Case %d: %d\n", x, (int)v.size()); 
    }
    
    return 0;
}
