#include <bits/stdc++.h>
using namespace std;

int t, n;
char c[6][5];
char d[6][5];
set<char> sim[5];

int main() {
    scanf("%d", &t);
    
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < 5; ++j)
                scanf(" %c", &c[i][j]);
                
        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < 5; ++j)
                scanf(" %c", &d[i][j]);
                
        for (int i = 0; i < 5; ++i) 
            for (int j = 0; j < 6; ++j) 
                for (int k = 0; k < 6; ++k) 
                    if (c[j][i] == d[k][i])
                        sim[i].insert(c[j][i]);                                    
        
        int mul = 1;
        for (int i = 0; i < 5; ++i)
            mul *= sim[i].size();
            
        if (n > mul) {
            printf("NO\n");
        } else {
            int co = 0;
            for (auto it0 = sim[0].begin(); it0 != sim[0].end() && co != n; ++it0) 
                for (auto it1 = sim[1].begin(); it1 != sim[1].end() && co != n; ++it1)
                    for (auto it2 = sim[2].begin(); it2 != sim[2].end() && co != n; ++it2)
                        for (auto it3 = sim[3].begin(); it3 != sim[3].end() && co != n; ++it3)
                            for (auto it4 = sim[4].begin(); it4 != sim[4].end() && co != n; ++it4) {
                                ++co;
                                if (co == n)
                                    printf("%c%c%c%c%c\n", *it0, *it1, *it2, *it3, *it4);
                            }
        }
        
        for (int i = 0; i < 5; ++i)
            sim[i].clear();
    }
    
    return 0;
}
