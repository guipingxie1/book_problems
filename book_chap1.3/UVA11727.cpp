#include <bits/stdc++.h>
using namespace std;

int t, a[3];

int main() {
    scanf("%d", &t);
    
    for (int x = 1; x <= t; ++x) {
        scanf("%d %d %d", a, a + 1, a + 2);
        sort(a, a + 3);
        printf("Case %d: %d\n", x, a[1]);
    }
    
    return 0;
}
