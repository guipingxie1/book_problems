#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    while (!cin.eof()) {
        int size = 1 << n;
        int a[size];
        int corn[size];
        memset(corn, 0, sizeof(corn));
        
        for (int i = 0; i < size; ++i) 
            cin >> a[i];
        
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) 
                    corn[i] += a[i - (1 << j)];
                else corn[i] += a[i + (1 << j)];
            }
        }
        
        int mi = 0;
        
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) 
                    mi = max(mi, corn[i] + corn[i - (1 << j)]);
                else mi = max(mi, corn[i] + corn[i + (1 << j)]);
            }
        }
        
        cout << mi << "\n";
        cin >> n;
    }
    
    return 0;
}
