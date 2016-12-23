#include <bits/stdc++.h>
using namespace std;

int n, m, q, x, y;
vector<int> a[505];

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
            int ma = 0;
            int j, k, d;
            
            for (int i = 0; i < n; ++i) {
                if (x > a[i][m - 1] || y < a[i][0]) 
                    continue;
                
                j = lower_bound(a[i].begin(), a[i].end(), x) - a[i].begin();
                
                if (y >= a[i][m - 1]) {
                    k = m - 1;
                } else {
                    k = lower_bound(a[i].begin(), a[i].end(), y) - a[i].begin();
                    if (k < m - 1) 
                        while (k < m - 1 && a[i][k + 1] == y) 
                            ++k;
                        
                    if (a[i][k] > y)
                        --k;
                }
                
                if (k >= j) {
                    d = min(n - 1 - i, k - j);
                    
                    if (d + 1 > ma) {
                        if (a[i + d][j + d] >= x && a[i + d][j + d] <= y) {
                            ma = d + 1;
                        } else {
                            int mid;   
                            int s = 0;                         
                            while (d > s) {
                                mid = s + (d - s) / 2;
                                
                                if (a[i + mid][j + mid] >= x && a[i + mid][j + mid] <= y) {
                                    s = mid + 1;
                                    ma = max(ma, s);
                                } else {
                                    d = mid;
                                }
                            }
                        }
                    }
                }
            }  
            
            for (int i = n - 1; i >= 0; --i) {
                if (x > a[i][m - 1] || y < a[i][0]) 
                    continue;
                
                j = lower_bound(a[i].begin(), a[i].end(), x) - a[i].begin();
                if (j != 0) 
                    while (j > 0 && a[i][j] == x) 
                        --j;
                        
                if (y >= a[i][m - 1]) {
                    k = m - 1;
                } else {
                    k = lower_bound(a[i].begin(), a[i].end(), y) - a[i].begin();
                    if (k < m - 1) 
                        while (k < m - 1 && a[i][k + 1] == y) 
                            ++k;
                    
                    if (a[i][k] > y)
                        --k;
                }
                
                if (k >= j) {
                    d = min(i, k - j);   
                    
                    if (d + 1 > ma) {
                        if (a[i - d][j] >= x && a[i - d][j] <= y) {
                            ma = d + 1;
                        } else {
                            int mid;   
                            int s = 0;                         
                            while (d > s) {
                                mid = s + (d - s) / 2;
                                
                                if (a[i - mid][j] >= x && a[i - mid][j] <= y) {
                                    s = mid + 1;
                                    ma = max(ma, s);
                                } else {
                                    d = mid;
                                }
                            }
                        }
                    }
                }
            }  
            
            printf("%d\n", ma);                     
        }
        
        for (int i = 0; i < n; ++i)
            a[i].clear();
            
        printf("-\n");
    }
    
    return 0;
}
