#include <bits/stdc++.h>
using namespace std;

int a[8][8];
int n;
unordered_map< bitset<16>, int > m;

int play(int co, int row, bitset<16> b) {
    if (m.find(b) != m.end())
        return m[b];
        
    if (co == n << 1)
        return 0;
        
    int ans;
        
    if (co & 1) {
        // Bob
        ans = 1000000000;
        for (int i = 0; i < n; ++i) {              
            bitset<16> bb = b;
            
            if (!b[8 + i]) {
                bb[row] = 1;
                bb[8 + i] = 1;
                ans = min(ans, a[row][i] + play(co + 1, row, bb));
            }
        }
    } else {
        ans = -1000000000;
        for (int i = 0; i < n; ++i)  
            if (!b[i])
                ans = max(ans, play(co + 1, i, b));
    }
    
    m[b] = ans;
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        scanf("%d", &n);
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &a[i][j]);
        
        int ans = -1000000000;
        for (int i = 0; i < n; ++i) {
            bitset<16> res;
            res[i] = 1;
            ans = max(ans, play(1, i, res));
        }
        
        printf("%d\n", ans);
        
        m.clear();
    }
    
    return 0;
}
