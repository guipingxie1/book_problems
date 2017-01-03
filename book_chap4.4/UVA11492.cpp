#include <bits/stdc++.h>
using namespace std;

int n, d, m;
bool v[255005];
vector< pair<int, string> > adj[5005];
pair<int, int> p;
string src, dest, x, y, z;
char c;
map<string, int> ma;

int main() {
    while (scanf("%d", &n), n) {
        int k = 2;
        cin >> src >> dest;
        ma[src] = 0;
        ma[dest] = 1;
        
        for (int i = 0; i < n; ++i) {
            cin >> x >> y >> z;
            if (ma.find(x) == ma.end())
                ma[x] = k++;
                
            if (ma.find(y) == ma.end())
                ma[y] = k++;
                
            adj[ma[x]].push_back(make_pair(ma[y], z));
            adj[ma[y]].push_back(make_pair(ma[x], z));
        }
        
        memset(v, false, sizeof(v));
        priority_queue< pair<int, int> > pq;
        
        for (int i = 0; i < adj[0].size(); ++i)
            pq.push(make_pair(-1 * adj[0][i].second.length(), 10000 * ((int)(adj[0][i].second[0] - 'a')) + adj[0][i].first));
            
        int ans = -1;        
        while(!pq.empty()) {
            p = pq.top();
            pq.pop();
            c = (char)((p.second / 10000) + 'a');
            d = p.first;
            m = p.second % 10000;
            
            if (!v[p.second]) {
                v[p.second] = true;
                
                if (m == 1) {
                    ans = -1 * d;
                    break;
                }
                
                for (int i = 0; i < adj[m].size(); ++i)
                    if (!v[10000 * ((int)(adj[m][i].second[0] - 'a')) + adj[m][i].first] && adj[m][i].second[0] != c) 
                        pq.push(make_pair(d - adj[m][i].second.length(), 10000 * ((int)(adj[m][i].second[0] - 'a')) + adj[m][i].first));
            }
        }
        
        if (ans == -1)
            printf("impossivel\n");
        else printf("%d\n", ans); 
            
        for (int i = 0; i < k; ++i)
            adj[i].clear();   
        ma.clear();
    }
    
    return 0;
}
