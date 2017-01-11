#include <bits/stdc++.h>
using namespace std;

int n, k, p;
vector<int> v;

int main() {
    v.push_back(0);
    for (int i = 1; i <= 4473; ++i)
        v.push_back((i * i + i) / 2);
        
    while (scanf("%d", &n) != EOF) {
        k = lower_bound(v.begin(), v.end(),  n) - v.begin();
        
        p = v[k] - n;        
        if (k & 1)
            printf("TERM %d IS %d/%d\n", n, 1 + p, k - p);
        else printf("TERM %d IS %d/%d\n", n, k - p, 1 + p);
    }
    
    return 0;
}
