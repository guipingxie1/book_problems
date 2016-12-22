#include <bits/stdc++.h>
using namespace std;

int m, n, k, x, y;
set<int> cant[105];
int ma;
bitset<105> ans;

void solve(int idx, bitset<105> b) {
    if (idx == n + 1) {
        if (b.count() > ma) {
            ma = b.count();
            ans = b;
        }
        
        return;
    }
    
    bool can = true;
    for (auto it = cant[idx].begin(); it != cant[idx].end(); ++it) {
        if (b[*it]) {
            can = false;
            break;
        }
    }
    
    if (can) {
        bitset<105> copy = b;
        copy[idx] = 1;
        solve(idx + 1, copy);
    }
    
    solve(idx + 1, b);
}

void solve() {
    for (int i = 1; i <= n; ++i) {
        bitset<105> b;
        b[i] = 1;
        solve(i + 1, b);       
    }
}

int main() {
    scanf("%d", &m);
    ma = 0;
    
    while (m--) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < k; ++i) {
            scanf("%d %d", &x, &y);
            cant[x].insert(y);
            cant[y].insert(x);
        }
        
        solve();
        
        printf("%d\n", ma);
        int co = 0;
        int idx = 0; 
        for (; co != ma - 1; ++idx) 
            if (ans[idx]) {
                printf("%d ", idx);
                ++co;
            }
        
        for (; co != ma; ++idx)
            if (ans[idx]) {
                printf("%d\n", idx);
                ++co;
            }
        
        ma = 0;
        for (int i = 1; i <= n; ++i)
            cant[i].clear();
    }
    
    return 0;
}
