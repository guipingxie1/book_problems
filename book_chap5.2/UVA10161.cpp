#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> v;

int main() {
    v.push_back(0);
    for (int i = 0; i < 44722; ++i)
        v.push_back(i * i + i + 1);
    
    while (scanf("%d", &n), n) {
        k = lower_bound(v.begin(), v.end(), n) - v.begin();
        
        if (v[k] == n) {
            printf("%d %d\n", k, k);
        } else {
            if (k & 1) {
                if (n > (k - 1) * (k - 1))
                    printf("%d %d\n", k, n - (k - 1) * (k - 1));
                else printf("%d %d\n", k - 1, (k - 1) - (n - v[k - 1]));
            } else {
                if (n > (k - 1) * (k - 1))
                    printf("%d %d\n",  n - (k - 1) * (k - 1), k);
                else printf("%d %d\n", (k - 1) - (n - v[k - 1]), k - 1);
            }
        }
    }
    
    return 0;
}
