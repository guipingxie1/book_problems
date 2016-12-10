#include <bits/stdc++.h>
using namespace std;

map< int, vector<int> > ma;

int main() {
    int n, m, x;
    while (cin >> n >> m) {
        if (cin.eof())
            break;
            
        ma.clear();
        for (int i = 1; i <= n; ++i) {
            cin >> x;
            if (ma.find(x) == ma.end()) {
                vector<int> v;
                ma[x] = v;
            }
            
            ma[x].push_back(i);            
        }
        
        while (m--) {
            cin >> n >> x;
            //cout << n << " " << x << " size: " << ma[x].size() << "\n"; 
            if (n > ma[x].size()) 
                cout << "0\n";
            else cout << ma[x][n - 1] << "\n";
        }
    }
    
    return 0;
}   

