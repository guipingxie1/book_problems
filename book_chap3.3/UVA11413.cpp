#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1005];

bool works(int k) {
    int c = 0;
    int i = 0;
    while (i != n && c != m) {
        //cerr << "BEGIN : " << k << " " << i << " " << c << "\n";
        int sum = 0;
        while ((i != n) && (sum + a[i] <= k)) {
            sum += a[i];
            ++i;
        }
        
        ++c; 
        //cerr << "END : " << k << " " << i << " " << c << "\n";
    }
    
    return i == n;
}

int main() {
    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 0; i < n; ++i)
            scanf("%d", a + i);
            
        int ma = 0;
        
        if (m >= n) {
            for (int i = 0; i < n; ++i)
                ma = max(ma, a[i]);
        } else {
            int e = ma = 1000000004;
            int s = 0;
            int mid;
            
            while (s < e) {
                mid = s + (e - s) / 2;
                if (works(mid)) {
                    e = mid;
                    ma = min(ma, mid);
                } else {
                    s = mid + 1;
                }                    
            }           
        }
        
        printf("%d\n", ma);
    }
    
    return 0;
}
