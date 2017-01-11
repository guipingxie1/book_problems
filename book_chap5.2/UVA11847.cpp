#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int k, n;


int main() {
    k = 0;
    while ((1 << k) <= 20000) {
        v.push_back(1 << k);
        ++k;
    }
    
    while (scanf("%d",&n), n) {
        k = lower_bound(v.begin(), v.end(), n) - v.begin();
        
        if (n == v[k])
            printf("%d\n", k);
        else printf("%d\n", k - 1);
    }
    
    return 0;
}
