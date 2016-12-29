#include <bits/stdc++.h>
using namespace std;

int t, n, m, ma;
int a[105][105];
int b[105];

int main() {
    scanf("%d", &t);
    
    for (int x = 1; x <= t; ++x) {
        int area = 0;
        int co = 0;
        scanf("%d %d %d", &n, &m, &ma);
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                scanf("%d", &a[i][j]);
                        
        for (int i = 0; i < n; ++i) {
            memset(b, 0, sizeof(b));
            
            for (int j = i; j < n; ++j) {
                for (int k = 0; k < m; ++k)
                    b[k] += a[j][k];
                
                int c = b[0];
                int len = 0;
                
                if (c <= ma) 
                    len = 1;
                else c = 0;
                    
                for (int k = 1; k < m; ++k) {
                    //cerr << b[k] << " " << (len * (j - i + 1)) << " " << c << " " << j << " " << k << "\n";
                    if (b[k] <= ma) {
                        if (c + b[k] <= ma) {
                            c += b[k];
                            ++len;      
                                                  
                            if ((len * (j - i + 1)) == area) {
                                if (co > c)
                                    co = c;
                            } else if ((len * (j - i + 1)) > area) {
                                area = len * (j - i + 1);
                                co = c;
                            }
                        } else {
                            if (c + b[k] - b[k - len] <= ma) {
                                c += b[k];
                                c -= b[k - len];    
                                                  
                                if ((len * (j - i + 1)) == area) {
                                    if (co > c)
                                        co = c;
                                } else if ((len * (j - i + 1)) > area) {
                                    area = len * (j - i + 1);
                                    co = c;
                                } 
                            } else {
                                int idx = k - 1;
                                len = 1;
                                c = b[k];
                                
                                while (idx >= 0) { 
                                    if (c + b[idx] <= ma) {
                                        c += b[idx];
                                        ++len;
                                        --idx;   
                                    } else {
                                        break;
                                    }
                                }
                                
                                if ((len * (j - i + 1)) == area) {
                                    if (co > c)
                                        co = c;
                                } else if ((len * (j - i + 1)) > area) {
                                    area = len * (j - i + 1);
                                    co = c;
                                }
                            }
                        }
                    } else {
                        len = 0;
                        c = 0;
                    }
                }
                
                c = b[0];
                len = 0;
                
                int s = j;
                int e = i;
                
                if (c <= ma) {
                    len = 1;
                } else {
                    if (a[j][0] < ma) {
                        while (c > ma) {
                            c -= a[e][0];
                            ++e;
                        }
                    } else {
                        c = 0;
                    }
                }
                
                if ((len * (s - e + 1)) == area) {
                    if (co > c)
                        co = c;
                } else if ((len * (s - e + 1)) > area) {
                    area = len * (s - e + 1);
                    co = c;
                }
            }               
        }
        
        printf("Case #%d: %d %d\n", x, area, co);
    }
    
    return 0;
}
