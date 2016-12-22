#include <bits/stdc++.h>
using namespace std;

int m, n;
int a[15];
map< int, vector<int> > ma;

int main() {
    while (scanf("%d %d", &m, &n), m || n) {
        for (int i = 0; i < n; ++i)
            scanf("%d", a + i);
            
        // Indices with bitshift    
        ma[0].push_back(0);
        for (int i = 0; i < n; ++i) 
            for (int j = m; j >= a[i]; --j) 
                if (ma.find(j - a[i]) != ma.end()) {
                    vector<int> v = ma[j - a[i]];
                    for (int k = 0; k < v.size(); ++k) {
                        int p = v[k] | 1 << i;
                        ma[j].push_back(p);
                    }
                }                 
            
        printf("Sums of %d:\n", m);
        if (ma.find(m) == ma.end()) {
            printf("NONE\n");
        } else {
            vector<int> v = ma[m];
            set< vector<int> > s;
            for (int i = 0; i < v.size(); ++i) {
                vector<int> k;
                for (int j = 0; j < n; ++j) 
                    if (v[i] & 1 << j)
                        k.push_back(a[j]);
                        
                s.insert(k);
            }
            
            for (auto it = s.rbegin(); it != s.rend(); ++it) {
                vector<int> k  = *it;
                for (int j = 0; j < (int)k.size() - 1; ++j)
                    printf("%d+", k[j]);
                printf("%d\n", k[(int)k.size() - 1]);
            }
        }
        
        ma.clear();
    }
    
    return 0;
}
