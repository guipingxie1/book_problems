#include <bits/stdc++.h>
using namespace std;

int t, r, c, p;
char a[55][55];

bool wo(int i) {
    for (int j = 0; j < c; ++j)
        if (a[i][j] == '0')
            return true;
            
    return false;
}

bool w() {
    for (int i = 0; i < r; ++i)
        if (!wo(i)) 
            return false;
            
    return true;
}

int mr(int i, int j) {
    ++j;
    int co = 1;
    
    while (j < c) {
        if (a[i][j] == '1')
            ++co;
        else break;
        
        ++j;
    }
    
    if (j == c && a[i][j - 1] == '1')
        return 10000000;
    
    return co;
}

int ml(int i, int j) {
    --j;
    int co = 1;
    
    while (j >= 0) {
        if (a[i][j] == '1')
            ++co;
        else break;
        
        --j;
    }
    
    if (j == -1 && a[i][0] == '1')
        return 10000000;
    
    return co;
}

int trav(int j) {
    int co = 0;
    for (int i = 0; i < r; ++i)
        if (a[i][j] == '1')
            co += min(mr(i, j), ml(i, j));
    
    return co;
}

int main() {
    scanf("%d", &t);
    for (int x = 1; x <= t; ++x) {
        scanf("%d %d", &r, &c);
        
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                scanf(" %c", &a[i][j]);
        
        p = 10000000;
        if (w()) {
            for (int j = 0; j < c; ++j)
                p = min(p, trav(j));            
        } else {
            p = -1;
        }
        
        printf("Case %d: %d\n", x, p);
    }
    
    return 0;
}
