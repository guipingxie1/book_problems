#include <bits/stdc++.h>
using namespace std;

int n, e, k, m, n1, n2, d;
int t[5];
vector<int> a[5];
bool v[500];
bool exist[100];
vector< pair<int, int> > adj[500];
pair<int, int> p;
string s;

int main() {
    while (scanf("%d %d", &n, &e) != EOF) {
        for (int i = 0; i < n; ++i)
            scanf("%d", t + i);
        
        memset(exist, false, sizeof(exist));
        
        cin.ignore();    
        for (int i = 0; i < n; ++i) {
            getline(cin, s);
            stringstream ss(s);
            
            while (ss >> m) {
                a[i].push_back(m);
                exist[m] = true;
            }
        }
        
        if (exist[e] && exist[0]) {
            if (n != e) {
                for (int i = 0; i < n; ++i) 
                    for (int j = 0; j < a[i].size(); ++j)
                        for (int k = j + 1; k < a[i].size(); ++k) {
                            d = t[i] * (a[i][k] - a[i][j]);
                            n1 = i * 100 + a[i][j];
                            n2 = i * 100 + a[i][k];
                            adj[n1].push_back(make_pair(d, n2));
                            adj[n2].push_back(make_pair(d, n1));
                        }
                
                for (int j = 1; j < 100; ++j) {
                    vector<int> vi;
                        
                    for (int i = 0; i < n; ++i)
                        if (!adj[100 * i + j].empty())
                            vi.push_back(i);
                    
                    if (vi.size() > 1) 
                        for (int i = 0; i < vi.size(); ++i)
                            for (int k = i + 1; k < vi.size(); ++k) {
                                adj[100 * vi[i] + j].push_back(make_pair(60, 100 * vi[k] + j));
                                adj[100 * vi[k] + j].push_back(make_pair(60, 100 * vi[i] + j));
                            }
                }
                
                priority_queue< pair<int, int> > pq;
                for (int i = 0; i < n; ++i)
                    if (!adj[100 * i].empty())        
                        pq.push(make_pair(0, 100 * i));
                
                memset(v, false, sizeof(v));
                
                int ans = -1;        
                while(!pq.empty()) {
                    p = pq.top();
                    pq.pop();
                    d = p.first;
                    m = p.second;
                    
                    if (!v[m]) {
                        v[m] = true;
                        
                        if ((m % 100) == e) {
                            ans = -1 * d;
                            break;
                        }
                        
                        for (int i = 0; i < adj[m].size(); ++i)
                            if (!v[adj[m][i].second]) 
                                pq.push(make_pair(d - adj[m][i].first, adj[m][i].second));
                    }
                }
                
                if (ans == -1)
                    printf("IMPOSSIBLE\n");
                else printf("%d\n", ans); 
                    
                for (int i = n * 100 - 1; i >= 0; --i)
                    adj[i].clear();
            } else {
                printf("0\n");
            }
        } else {
            printf("IMPOSSIBLE\n");
        }                 
            
        for (int i = 0; i < n; ++i)
            a[i].clear();
    }
    
    return 0;
}
