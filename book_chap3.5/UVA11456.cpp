#include <bits/stdc++.h>
using namespace std;

int t, n;
int a[2005];

int lis(int idx) {
    vector<int> v;
    v.push_back(a[idx]);
    int pos = idx;
    
    for (int i = idx + 1; i < n; ++i) {
        pos = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
        
        if (pos == v.size()) 
            v.push_back(a[i]);
        else if (pos != 0)
            v[pos] = a[i];
    }
    
    return (int)v.size();
}

int lds(int idx) {
    vector<int> v;
    v.push_back(a[idx]);
    int pos = idx;
    
    for (int i = idx + 1; i < n; ++i) {
        if (a[i] < v.back()) {
            v.push_back(a[i]);
        } else {
            if (a[i] < v[0]) {
                int s = 1;
                int e = (int)v.size() - 1;
                int mid = s + (e - s) / 2;
                
                while (s < e) {
                    mid = s + (e - s) / 2;
                    if (a[i] < v[mid])
                        s = mid + 1;
                    else e = mid;
                }
                
                if (a[i] > v[mid]) {
                    v[mid] = a[i];                    
                } else if (a[i] > v[s]) {
                    v[s] = a[i];
                }
            }
        }
    }
    
    return (int)v.size();
}

int main() {
    scanf("%d", &t);
    
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", a + i);
            
        int ma = 0;    
        for (int i = 0; i < n; ++i) 
            ma = max(ma, lis(i) + lds(i) - 1);
        
        printf("%d\n", ma);
    }
    
    return 0;
}
