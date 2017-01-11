#include <bits/stdc++.h>
using namespace std;

int n, k;
vector< pair<double, pair<int, int> > > v;

int gcd(int x, int y) {
    if (y == 0)
        return x;
        
    return gcd(y, x % y);
}

int main() {
    while (scanf("%d %d", &n, &k) == 2) {
        v.push_back(make_pair(1.0, make_pair(1, 1)));
        
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
                if (gcd(i, j) == 1)
                    v.push_back(make_pair((double)i / (double)j, make_pair(i, j)));
        
        sort(v.begin(), v.end());
        
        printf("%d/%d\n", v[k - 1].second.first, v[k - 1].second.second);
        
        v.clear();
    }
    
    return 0;
}
