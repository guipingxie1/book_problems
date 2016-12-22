#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[16][2];
set<int> poss[18];

bool place(int idx, int prev, vector<int> v, int k) {
    if (idx == n + 1)
        return a[m + 1][0] == prev;
    
    for (auto it = poss[v[idx - 1]].begin(); it != poss[v[idx - 1]].end(); ++it) {
        int x = a[*it][0];
        int y = a[*it][1];
        bool b = false;
        //cerr << *it << " " << x << " " << y << " " << idx << " " << prev << "\n";
        
        if (!(k & 1 << *it)) { 
            v[idx] = *it;
            if (x == prev)
                b = place(idx + 1, y, v, k | 1 << *it);
            else if (y == prev)
                b = place(idx + 1, x, v, k | 1 << *it);
            
            if (b)
                return true;
        }             
    }
    
    return false;
}

int main() {
    while (scanf("%d %d", &n, &m), n) {
        scanf("%d %d %d %d", &a[0][0], &a[0][1], &a[m + 1][0], &a[m + 1][1]);
        for (int i = 1; i <= m; ++i)
            scanf("%d %d", &a[i][0], &a[i][1]);
        
        for (int i = 1; i <= m; ++i) {
            if (a[0][1] == a[i][1] || a[0][1] == a[i][0])
                poss[0].insert(i);
        
            if (a[m + 1][0] == a[i][0] || a[m + 1][0] == a[i][1])
                poss[m + 1].insert(i);
        }
        
        for (int i = 1; i <= m; ++i) 
            for (int j = 1; j <= m; ++j) 
                if (i != j) 
                    if (a[i][0] == a[j][0] || a[i][1] == a[j][1] || a[i][0] == a[j][1] || a[i][1] == a[j][0])
                        poss[i].insert(j);   
/*                        
        for (int i = 0; i <= m + 1; ++i) {
            cerr << "TESTING : " << i << " (" << a[i][0] << "," << a[i][1] << ")\n";
            for (auto it = poss[i].begin(); it != poss[i].end(); ++it)
                cerr << *it << " (" << a[*it][0] << "," << a[*it][1] << ") ";
            cerr << "\n";
        }             
*/        
        vector<int> v(n + 1);
        v[0] = 0;
        if (place(1, a[0][1], v, 1 << 0))
            printf("YES\n");
        else printf("NO\n");
        
        for (int i = 0; i < 18; ++i)
            poss[i].clear();
    }
    
    return 0;
}
