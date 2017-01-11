#include <bits/stdc++.h>
using namespace std;

int n, k, p, o, m;
vector<int> v;

int main() {
    int idx = 0;
    while (k < 100000) {
        k = 3 * idx * idx + 3 * idx + 1;
        v.push_back(k);
        ++idx;
    }
    
    while (scanf("%d", &n) == 1) {
        k = lower_bound(v.begin(), v.end(), n) - v.begin();
        
        if (n == v[k]) {
            printf("%d 0\n", k);
        } else {
            p = (n - v[k - 1]) / k;
            m = v[k - 1] + 1 + p * k; 
            o = n - m;
            
            if (p == 0) {
                printf("%d %d\n", k - 1 - o, 1 + o);
            } else if (p == 1) {
                printf("%d %d\n", -1 - o, k);
            } else if (p == 2) {
                printf("%d %d\n", -k, k - 1 - o);
            } else if (p == 3) {
                printf("%d %d\n", o - (k - 1), -1 - o);
            } else if (p == 4) {
                printf("%d %d\n", 1 + o, -k);
            } else if (p == 5) {
                printf("%d %d\n", k, o - (k - 1));
            } 
        }
    }
    
    return 0;
}
