#include <bits/stdc++.h>
using namespace std;

int n;
int a[52];

int main() {
    int co = 1;
    while (scanf("%d", &n), n) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
            sum += a[i];
        }
        
        int k = sum / n;
        int c = 0;
        for (int i = 0; i < n; ++i) 
            c += abs(a[i] - k);
        
        printf("Set #%d\nThe minimum number of moves is %d.\n\n", co++, c / 2);
    }
    
    return 0;
}
