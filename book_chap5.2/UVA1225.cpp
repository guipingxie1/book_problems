#include <bits/stdc++.h>
using namespace std;

vector<int> a[10005];
int t, n;

int main() {
    vector<int> v(10);
    v[1] = 1;
    a[1] = v;
    
    for (int i = 2; i <= 10000; ++i) {
        int te[10];
        memset(te, 0, sizeof(te));
        
        int k = i;
        while (k) {
            te[k % 10]++;
            k /= 10;
        }
        
        for (int j = 0; j < 10; ++j)
            v[j] += te[j];
            
        a[i] = v;
    }
    
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%d %d %d %d %d %d %d %d %d %d\n", a[n][0], a[n][1], a[n][2], a[n][3], a[n][4], a[n][5], a[n][6], a[n][7], a[n][8], a[n][9]);
    }
    
    return 0;
}
