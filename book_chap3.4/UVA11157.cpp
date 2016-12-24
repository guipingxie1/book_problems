#include <bits/stdc++.h>
using namespace std;

int t, n, d, k, p, e, idx;
char c, dash;
int st[105];
bool sm[105];
vector< pair<int, int> > v;

void get_cont() {
    int p = 0;
    int j = 0;
    while (j < n) {
        if (sm[j]) {
            p = j;
            while (j < n && sm[j])
                ++j;
            
            if (j - p > 1) 
                v.push_back(make_pair(p, j - 1));                    
        } 
        
        ++j;
    }
}

int main() {
    scanf("%d", &t);
    
    for (int x = 1; x <= t; ++x) {
        scanf("%d %d", &n, &d);
        
        int mi = d;
        memset(sm, false, sizeof(sm));
        
        for (int i = 0; i < n; ++i) {
            scanf(" %c %c %d", &c, &dash, st + i);
            
            if (c == 'S')
                sm[i] = true;
        }
                
        if (n == 1) {
            if (!sm[0])
                mi = max(d - st[0], st[0]);
        } else if (n == 2) {
            int co = 0;
            if (sm[0]) ++co;
            if (sm[1]) ++co;
            
            if (co == 2) {
                mi = max(st[1], d - st[0]);
            } else if (co == 1) {
                if (sm[0])
                    mi = max(d - st[1], st[1]);
                else mi = max(d - st[0], st[0]);
            } else {
                mi = max(d - st[1], max(st[0], st[1] - st[0]));
            }
        } else if (n > 2) {
            // Simulate it
            get_cont();
            
            if (v.size()) {
                // Start at v[0]
                if (v[0].first == 0) {
                    // End at v[0] too
                    if (v[0].second == n - 1) {
                        mi = max(d - st[n - 2], st[1]);
                        for (int i = 0; i < n / 2; ++i) 
                            mi = max(mi, st[i + 2] - st[i]);
                    } else {
                        mi = max(st[v[0].second + 1] - st[v[0].second - 1], st[1]);
                        
                        k = v[0].second - v[0].first - 1;
                        for (int i = 0; i < k; ++i) 
                            mi = max(mi, st[i + 2] - st[i]);
                    }
                } else {
                    p = 0;
                    e = v[0].first - 1;
                    if (!sm[0]) {
                        mi = st[0];
                    } else {
                        p = 1;
                        mi = st[1];
                    }
                    
                    idx = p;
                    while (idx <= e && sm[idx])
                        ++idx;
                    
                    while (idx <= e) {
                        if (!sm[idx]) {
                            mi = max(mi, st[idx] - st[p]);
                            p = idx;
                        }
                        
                        ++idx;
                    } 
                    
                    if (v[0].second == n - 1) {
                        mi = max(mi, max(d - st[v[0].second - 1], st[v[0].first + 1] - st[v[0].first - 1]));
                        
                        k = v[0].second - v[0].first - 1;
                        for (int i = 0; i < k; ++i) 
                            mi = max(mi, st[v[0].first + i + 2] - st[v[0].first + i]);
                    } else {
                        mi = max(mi, max(st[v[0].second + 1] - st[v[0].second - 1], st[v[0].first + 1] - st[v[0].first - 1]));
                        
                        k = v[0].second - v[0].first - 1; 
                        for (int i = 0; i < k; ++i) 
                            mi = max(mi, st[v[0].first + i + 2] - st[v[0].first + i]);
                    }
                } 
                
                if (v.size() == 1) {
                    p = 1 + v[0].second;
                    idx = p;
                    while (idx < n && sm[idx])
                        ++idx;
                        
                    while (idx < n) {
                        if (!sm[idx]) {
                            mi = max(mi, st[idx] - st[p]);
                            p = idx;
                        }
                        
                        ++idx;
                    }
                    
                    if (p != n)
                        mi = max(mi, d - st[p]); 
                } else {
                    p = 1 + v[0].second;
                    e = v[1].first - 1;
                    idx = p;
                    
                    while (idx <= e && sm[idx])
                        ++idx;
                        
                    while (idx <= e) {
                        if (!sm[idx]) {
                            mi = max(mi, st[idx] - st[p]);
                            p = idx;
                        }
                        
                        ++idx;
                    }
                
                    for (int i = 1; i < (int)v.size() - 1; ++i) {
                        // Do calculations
                        mi = max(mi, max(st[v[i].second + 1] - st[v[i].second - 1], st[v[i].first + 1] - st[v[i].first - 1]));
                        k = v[i].second - v[i].first - 1;     
                        for (int j = 0; j < k; ++j) 
                            mi = max(mi, st[v[i].first + j + 2] - st[v[i].first + j]);
                        
                        p = 1 + v[i].second;
                        e = v[i + 1].first - 1;
                        idx = p;
                        while (idx <= e && sm[idx])
                            ++idx;
                            
                        while (idx <= e) {
                            if (!sm[idx]) {
                                mi = max(mi, st[idx] - st[p]);
                                p = idx;
                            }
                            
                            ++idx;
                        }
                    }
                    
                    if (v.size() > 1) {
                        // Need to end at v[(int)v.size() - 1]
                        int sz = (int)v.size() - 1;
                        if (v[sz].second == n - 1) {
                            mi = max(mi, max(d - st[v[sz].second - 1], st[v[sz].first + 1] - st[v[sz].first - 1]));
                            
                            k = v[sz].second - v[sz].first - 1;
                            for (int i = 0; i < k; ++i) 
                                mi = max(mi, st[v[sz].first + i + 2] - st[v[sz].first + i]);
                        } else {
                            mi = max(mi, max(st[v[sz].second + 1] - st[v[sz].second - 1], st[v[sz].first + 1] - st[v[sz].first - 1]));
                            k = v[sz].second - v[sz].first - 1;
                            for (int i = 0; i < k; ++i) 
                                mi = max(mi, st[v[sz].first + i + 2] - st[v[sz].first + i]);
                                
                            p = 1 + v[sz].second;
                            idx = p;
                            
                            while (idx < n && sm[idx])
                                ++idx;
                                
                            while (idx < n) {
                                if (!sm[idx]) {
                                    mi = max(mi, st[idx] - st[p]);
                                    p = idx;
                                }
                                
                                ++idx;
                            }
                            
                            mi = max(mi, d - st[p]); 
                        }   
                    }
                }
            } else {
                p = 0;
                if (!sm[0]) {
                    mi = st[0];
                } else {
                    p = 1;
                    mi = st[1];
                }
                
                idx = p;
                while (idx < n && sm[idx])
                    ++idx;
                
                while (idx < n) {
                    if (!sm[idx]) {
                        mi = max(mi, st[idx] - st[p]);
                        p = idx;
                    }
                    
                    ++idx;
                }
                
                mi = max(mi, d - st[p]); 
            }
            
            v.clear();
        }
        
        printf("Case %d: %d\n", x, mi);
    }
    
    return 0;
}
