#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, t, x;
    while (1) {
        cin >> n >> m;
        if (cin.eof())
            break;
            
        vector< pair<int, int> > v[m + 1];
        for (int i = 1; i <= n; ++i) {
            cin >> t;
            int a[t];
            for (int j = 0; j < t; ++j)
                cin >> a[j];
                
            for (int j = 0; j < t; ++j) {
                cin >> x;
                v[a[j]].push_back(make_pair(i, x));
            }
        }
        
        cout << m << " " << n << endl;
        for (int i = 1; i <= m; ++i) {
            if (v[i].size())
                cout << v[i].size() << " ";
            else cout << "0";            
            
            for (int j = 0; j < (int)v[i].size() - 1; ++j) 
                cout << v[i][j].first << " ";
                
            if (v[i].size())
                cout << v[i][v[i].size() - 1].first << endl;
            else cout << endl;
                        
            for (int j = 0; j < (int)v[i].size() - 1; ++j) 
                cout << v[i][j].second << " ";
                
            if (v[i].size())
                cout << v[i][v[i].size() - 1].second << endl;
            else cout << endl;
        }
    }

    return 0;
}
