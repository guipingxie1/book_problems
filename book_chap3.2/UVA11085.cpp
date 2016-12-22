#include <bits/stdc++.h>
using namespace std;

int q[8];
vector< vector<int> > vv;

bool is_valid() {
    int rows = 0;
    int diag = 0;
    int opp_diag = 0;
    for (int i = 0; i < 8; ++i) {
        if (rows & 1 << q[i])
            return false;
        else rows |= 1 << q[i];
        
        if (diag & 1 << (1 + i + q[i]))
            return false;
        else diag |= 1 << (1 + i + q[i]);
        
        if (opp_diag & 1 << (7 - i + q[i]))
            return false;
        else opp_diag |= 1 << (7 - i + q[i]); 
    }
    
    return true;
}

bool is_valid(int a[]) {
    int rows = 0;
    int diag = 0;
    int opp_diag = 0;
    for (int i = 0; i < 8; ++i) {
        if (rows & 1 << a[i])
            return false;
        else rows |= 1 << a[i];
        
        if (diag & 1 << (1 + i + a[i]))
            return false;
        else diag |= 1 << (1 + i + a[i]);
        
        if (opp_diag & 1 << (7 - i + a[i]))
            return false;
        else opp_diag |= 1 << (7 - i + a[i]); 
    }
    
    return true;
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    
    do {
        if (is_valid(a)) {
            vector<int> v;
            for (int i = 0; i < 8; ++i)
                v.push_back(a[i]);
                
            vv.push_back(v);
        }
    } while (next_permutation(a, a + 8));

    int c = 1;
    while (scanf("%d %d %d %d %d %d %d %d", q, q + 1, q + 2, q + 3, q + 4, q + 5, q + 6, q + 7) != EOF) {
        int m = 7;
        // Max = 7 - use for pruning
        
        for (int i = 0; i < vv.size(); ++i) {
            int diff = 0;
            
            for (int j = 0; j < 8; ++j) 
                if (q[j] != vv[i][j])
                    ++diff;
            
            m = min(m, diff);
        }
        
        printf("Case %d: %d\n", c++, m);
    }
    
    return 0;
}
