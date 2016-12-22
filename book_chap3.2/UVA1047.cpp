#include <bits/stdc++.h>
using namespace std;

vector< bitset<20> > vv;
vector< set<int> > cont[21];
vector<int> cont_val[21];
set< set<int> > hit;
int n, m;

void gen_combo(int idx, int curr, bitset<20> bv) {
    if (idx > n || curr > m)
        return;
        
    if (curr == m) {
        vv.push_back(bv);
        return;
    }
       
    if (idx != n) { 
        gen_combo(idx + 1, curr, bv);
        
        bv[idx] = 1;
        gen_combo(idx + 1, curr + 1, bv);
    }
}

int main() {
    int p, t, v, x;
    int c = 1;
    while (scanf("%d %d", &n, &m), n || m) {
        int a[n];
        for (int i = 0; i < n; ++i)
            scanf("%d", a + i);
            
        scanf("%d", &p);
        
        for (int i = 0; i < p; ++i) {
            scanf("%d", &t);
            int d[t];
            
            for (int j = 0; j < t; ++j)
                scanf("%d", d + j);
                
            scanf("%d", &v);
            
            set<int> s;                
            for (int j = 0; j < t; ++j)
                s.insert(d[j]);
            
            for (int j = 0; j < t; ++j) {
                cont[d[j]].push_back(s);
                cont_val[d[j]].push_back(v);
            }
        }
        
        bitset<20> ignore;
        gen_combo(0, 0, ignore);
        
        int ma = 0;
        int idx = 0;
        
        for (int i = 0; i < vv.size(); ++i) {
            hit.clear();
            vector<int> bv;
            int sum = 0;
        
            for (int j = 0; j < n; ++j) 
                if (vv[i][j]) {
                    bv.push_back(j + 1);
                    sum += a[j];
                }
                
            if (sum >= ma) {
                for (int j = 0; j < bv.size() && sum >= ma; ++j) 
                    for (int k = 0; k < cont[bv[j]].size() && sum >= ma; ++k) 
                        if (hit.find(cont[bv[j]][k]) == hit.end()) {
                            hit.insert(cont[bv[j]][k]);
                            int co = 0;
                            
                            for (int l = j; l < bv.size(); ++l) 
                                if (cont[bv[j]][k].find(bv[l]) != cont[bv[j]][k].end())
                                    ++co;
                            
                            if (co > 1)
                                sum -= (co - 1) * cont_val[bv[j]][k];
                        }
                    
                
                if (sum >= ma) {
                    if (sum == ma) {
                        bool less = true;
                        for (int j = 0; j < n; ++j) {
                            if (vv[i][j] && !vv[idx][j]) {
                                break;
                            } else if (!vv[i][j] && vv[idx][j]) {
                                less = false;
                                break;
                            }
                        }
                    
                        if (less) {
                            ma = sum;
                            idx = i;
                        }
                    } else {
                        ma = sum;
                        idx = i;
                    }
                }
            }
        }
        
        printf("Case Number  %d\nNumber of Customers: %d\nLocations recommended: ", c++, ma);
        
        int ans[m];
        int j = 0;
        for (int i = 0; i < n; ++i) 
            if (vv[idx][i]) 
                ans[j++] = i;
            
        for (int i = 0; i < m - 1; ++i)
            printf("%d ", ans[i] + 1);
        printf("%d\n\n", ans[m - 1] + 1);

        vv.clear();
        for (int i = 1; i < 21; ++i) {
            cont[i].clear();
            cont_val[i].clear();
        }
    }
    
    return 0;
}
