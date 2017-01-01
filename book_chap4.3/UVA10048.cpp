#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e, q, a, b, w;
    int c = 1;
    
    while (cin >> n >> e >> q, n || e || q) {
        if (c != 1)
            cout << "\n";
            
        int dist[n + 1][n + 1];
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j)
                dist[i][j] = 10000000;
            dist[i][i] = 0;
        }
            
        for (int i = 0; i < e; ++i) {
            cin >> a >> b >> w;
            dist[a][b] = w;
            dist[b][a] = w;
        }
        
        for (int k = 1; k <= n; ++k) 
            for (int i = 1; i <= n; ++i) 
                for (int j = 1; j <= n; ++j) 
                    dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));
        
        cout << "Case #" << c++ << "\n";
        
        while (q--) {
            cin >> a >> b;
            
            if (dist[a][b] == 10000000)
                cout << "no path\n";
            else cout << dist[a][b] << "\n";
        }
    }
    
    return 0;
}
