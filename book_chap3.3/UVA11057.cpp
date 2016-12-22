#include <bits/stdc++.h>
using namespace std;

int n, sum, x, a, b;
map<int, int> m;

int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            ++m[x];   
        }
        
        scanf("%d", &sum);
        
        bool done = false;
        if (sum % 2 == 0) 
            if (m.find(sum >> 1) != m.end())
                if (m[sum >> 1] > 1) {
                    printf("Peter should buy books whose prices are %d and %d.\n\n", sum >> 1, sum >> 1);
                    done = true;
                }
       
        int mi = 1000000;
        auto res = m.begin();
        if (!done) {
            for (auto it = m.begin(); it != m.end(); ++it) 
                if (sum != (it -> first) << 1) 
                    if ((res = m.find(sum - it -> first)) != m.end()) {
                        if (abs(res -> first - it -> first) < mi) {
                            mi = abs(res -> first - it -> first);
                            a = min(res -> first, it -> first);
                            b = max(res -> first, it -> first);
                        } else {
                            break;
                        }
                    }
            
            printf("Peter should buy books whose prices are %d and %d.\n\n", a, b);   
        }
        
        m.clear();
    }
    
    return 0;
}
