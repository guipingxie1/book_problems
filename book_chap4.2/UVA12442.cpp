#include <bits/stdc++.h>
using namespace std;

int t, n, u, v, mc, idx;

int f[50005];
bool is[50005];
int in[50005];
set<int> s;
int cap;

int solve(int k) {
    if (k == -1 || f[k] == -1) {
        cap = -1;
        return 0;
    }
        
    if (s.find(k) != s.end()) {
        cap = k;
        return 0;
    }    
        
    s.insert(k);

    if (in[k] != 0) {
        cap = -1;
        return in[k];       
    }
        
    return in[k] = 1 + solve(f[k]);
}

int main() {
    scanf("%d", &t);
    
    for (int x = 1; x <= t; ++x) {
        scanf("%d", &n);
        memset(is, false, sizeof(is));
        memset(f, -1, sizeof(f));
        memset(in, 0, sizeof(in));
        
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &u, &v);          
            f[u] = v;  
            is[u] = true;  
        }
        
        idx = mc = 0;
        
        for (int i = 1; i <= n; ++i) 
            if (is[i]) 
                if (in[i] == 0) {
                    s.insert(i);
                    in[i] = 1 + solve(f[i]);
                    s.clear();
                    
                    if (cap != -1) {
                        int p = f[cap];
                        while (p != cap) {
                            in[p] = in[cap];
                            p = f[p];
                        }
                    }
                    
                    cap = -1;
                }
                    
        for (int i = 1; i <= n; ++i)
            if (is[i])
                if (in[i] > mc) {
                    mc = in[i];
                    idx = i;
                }    
        
        printf("Case %d: %d\n", x, idx);
    }
    
    return 0;
}
