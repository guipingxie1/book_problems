#include <bits/stdc++.h>
using namespace std;

int n, u, v, e;
int d[26][26];
int od[26][26];
char m, b, x, y; 

int main() {
    while (scanf("%d", &n), n) {
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j)
                d[i][j] = od[i][j] = 10000000;
            d[i][i] = od[i][i] = 0;
        }
            
        for (int i = 0; i < n; ++i) {
            scanf(" %c %c %c %c %d", &m, &b, &x, &y, &e);
            u = x - 'A';
            v = y - 'A';
            if (m == 'Y') {
                if (b =='B') 
                    d[v][u] = e;
                
                d[u][v] = e;
            } else {
                if (b =='B') 
                    od[v][u] = e;
                
                od[u][v] = e;
            }
        }
        
        for (int i = 0; i < 26; ++i)
            d[i][i] = od[i][i] = 0;
        
        scanf(" %c %c", &x, &y);
        u = x - 'A';
        v = y - 'A';
        
        for (int k = 0; k < 26; ++k)
            for (int i = 0; i < 26; ++i)
                for (int j = 0; j < 26; ++j) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                    od[i][j] = min(od[i][j], od[i][k] + od[k][j]);
                }
        
        int mi = 10000000;
        vector<int> idx;
        for (int i = 0; i < 26; ++i) {
            if (d[u][i] + od[v][i] == mi) {
                idx.push_back(i);
            } else if (d[u][i] + od[v][i] < mi) {
                mi = d[u][i] + od[v][i];
                idx.clear();
                idx.push_back(i);
            }        
        }
            
        if (mi == 10000000) {
            printf("You will never meet.\n");
        } else {
            printf("%d", mi);
            for (int i = 0; i < idx.size(); ++i)
                printf(" %c", (char)(idx[i] + 'A'));
            printf("\n");
        }
    }
    
    return 0;
}
