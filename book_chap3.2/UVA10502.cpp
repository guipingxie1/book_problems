#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[105][105];

int main() {
    while (scanf("%d %d", &n, &m), n) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                scanf(" %c", &a[i][j]);

        int co = 0;
        bool flag = true;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (a[i][j] == '1') {
                    flag = true;
                    
                    for (int k = i; k < n; ++k)
                        for (int l = j; l < m; ++l) {
                            for (int x = i; x <= k && flag; ++x)
                                for (int y = j; y <= l && flag; ++y)
                                    if (a[x][y] == '0')
                                        flag = false;
                                        
                            if (flag)
                                ++co;
                            else flag = true;
                        }     
                }   
            
        printf("%d\n", co);
    }
        
    return 0;
}
