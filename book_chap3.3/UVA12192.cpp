#include <bits/stdc++.h>
using namespace std;

int n, m, q, x, y;
vector<int> a[505];
int b[505][2];

int main() {
    while (scanf("%d %d", &n, &m), n || m) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                scanf("%d", &q);
                a[i].push_back(q);   
            }
                
        scanf("%d", &q);
        while (q--) {
            scanf("%d %d", &x, &y);
            
            for (int i = 0; i < n; ++i) {
                if (x > a[i][m - 1] || y < a[i][0]) {
                    b[i][0] = b[i][1] = 0;
                    cerr << b[i][0] << " " << b[i][1] << "\n";
                    continue;
                }
                
                b[i][0] = lower_bound(a[i].begin(), a[i].end(), x) - a[i].begin();
                
                if (y >= a[i][m - 1]) {
                    b[i][1] = m - 1;
                } else {
                    b[i][1] = lower_bound(a[i].begin(), a[i].end(), y) - a[i].begin();
                    if (a[i][b[i][1]] > y)
                        --b[i][1];
                }
                
                cerr << b[i][0] << " " << b[i][1] << "\n";
            }
            
            cerr << "--\n";                        
        }
        
        for (int i = 0; i < n; ++i)
            a[i].clear();
            
        printf("-\n");
    }
    
    return 0;
}
