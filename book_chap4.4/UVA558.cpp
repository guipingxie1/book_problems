#include <bits/stdc++.h>
using namespace std;

vector< pair<int, int> > adj[1005];

int main() {
    int t, n, e, a, b, w;
    cin >> t;
    
    while (t--) {
        for (int i = 0; i < 1001; ++i)
            adj[i].clear();
            
        cin >> n >> e;
        
        for (int i = 0; i < e; ++i) {
            cin >> a >> b >> w;
            adj[a].push_back(make_pair(b, w));
        }
        
        int dist[n];
        dist[0] = 0;
        
        for (int i = 1; i < n; ++i)
            dist[i] = 10000000;
        
        for (int i = 0; i < n - 1; ++i) 
            for (int j = 0; j < n; ++j) {
                vector< pair<int, int> > j_adj = adj[j];
                
                for (int k = 0; k < j_adj.size(); ++k) {
                    int adj_v = j_adj[k].first;
                    int wei = j_adj[k].second;
                    
                    if (dist[adj_v] > dist[j] + wei)
                        dist[adj_v] = dist[j] + wei;
                }
            }
        
        bool flag = false;
        
        for (int j = 0; j < n && !flag; ++j) {
            vector< pair<int, int> > j_adj = adj[j];
            
            for (int k = 0; k < j_adj.size(); ++k) {
                int adj_v = j_adj[k].first;
                int wei = j_adj[k].second;
                
                if (dist[adj_v] > dist[j] + wei) {
                    flag = true;
                    break;
                }
            }
        }
        
        if (flag)
            cout << "possible\n";
        else cout << "not possible\n";
    }
    
    return 0;
}
