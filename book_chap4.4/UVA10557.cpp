#include <bits/stdc++.h>
using namespace std;

int n, m, k, x;
vector<int> a[105];
int e[105];
int d[105];

int di[105];
int rd[105];
vector<int> ra[105];
pair<int, int> p;

int main() {
    while (scanf("%d", &n), n != -1) {
        bool can = false;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", e + i);
            scanf("%d", &m);
            
            for (int j = 0; j < m; ++j) {
                scanf("%d", &k);
                a[i].push_back(k);
                ra[k].push_back(i);
                
                if (k == n)
                    can = true;
            }
            
            d[i] = -100000000;
        }
        
        if (can) {
            set<int> ss;
            for (int i = 1; i <= n; ++i) 
                di[i] = rd[i] = -10000000;
            
            priority_queue< pair<int, int> > pq;
            pq.push(make_pair(0, 1));        
            
            while (!pq.empty()) {
                p = pq.top();
                pq.pop();
                
                k = p.first;
                x = p.second;
                
                if (di[x] == -10000000) {
                    di[x] = -1 * k;
                    
                    for (int i = 0; i < a[x].size(); ++i)
                        if (di[a[x][i]] == -10000000) 
                            pq.push(make_pair(k - e[a[x][i]], a[x][i]));
                }
            }
            
            pq.push(make_pair(0, n));        
            
            while (!pq.empty()) {
                p = pq.top();
                pq.pop();
                
                k = p.first;
                x = p.second;
                
                if (rd[x] == -10000000) {
                    rd[x] = -1 * k;
                    
                    for (int i = 0; i < ra[x].size(); ++i)
                        if (rd[ra[x][i]] == -10000000) 
                            pq.push(make_pair(k - e[ra[x][i]], ra[x][i]));
                }
            }
            
            for (int i = 1; i <= n; ++i)
                if (di[i] != -10000000 && rd[i] != -10000000)
                    ss.insert(i);            
            
            d[1] = 100;
            for (int x = 1; x < n; ++x)
                for (int i = 1; i <= n; ++i)
                    if (d[i] != -100000000)
                        for (int j = 0; j < a[i].size(); ++j)
                            if (d[i] + e[a[i][j]] > 0 && d[a[i][j]] < d[i] + e[a[i][j]])
                                d[a[i][j]] = d[i] + e[a[i][j]];
            
            if (d[n] > 0) {
                printf("winnable\n");
            } else {
                bool works = false;
                for (int i = 1; i <= n; ++i)
                    if (d[i] != -100000000)
                        for (int j = 0; j < a[i].size(); ++j)
                            if (d[i] + e[a[i][j]] > 0 && d[a[i][j]] < d[i] + e[a[i][j]])
                                if (ss.find(i) != ss.end())
                                    works = true;
                
                if (works)
                    printf("winnable\n");
                else printf("hopeless\n"); 
            }        
        } else {
            printf("hopeless\n");
        }
        
        for (int i = 1; i <= n; ++i) {
            a[i].clear();
            ra[i].clear();
        }
    }
    
    return 0;
}
