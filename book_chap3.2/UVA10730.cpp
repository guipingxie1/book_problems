#include <bits/stdc++.h>
using namespace std;

int n;
int a[10005];
bool b[10005];

bool check() {
    memset(b, false, sizeof(b));
    b[a[0]] = true;
    
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j)
            if (a[i] + a[i] - a[j] < n && a[i] + a[i] - a[j] >= 0 && !b[a[i] + a[i] - a[j]]) 
                return true;
            
        b[a[i]] = true;
    }
    
    return false;
}

int main() {
    while (scanf("%d:", &n), n) {
        for (int i = 0; i < n; ++i)
            scanf("%d", a + i);
        
        if (check())
            printf("no\n");
        else printf("yes\n");
    }
    
    return 0;
}
