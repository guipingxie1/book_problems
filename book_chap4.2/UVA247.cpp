#include <bits/stdc++.h>
using namespace std;

int n, m, k, x;
map<string, int> ma;
set<int> a[28];
bool visit[28];
int low[28];
int high[28];
string s[28];
string s1, s2;
stack<int> st;
set< vector<int> > ans;

void dfs(int t) {
    low[t] = high[t] = ++x;
    st.push(t);
    
    for (auto it = a[t].begin(); it != a[t].end(); ++it) {
        if (!visit[*it]) {
            visit[*it] = true;
            dfs(*it);
        }
        
        if (visit[*it]) 
            low[t] = min(low[t], low[*it]);        
    }
    
    if (low[t] == high[t]) {
        vector<int> sol;
        sol.push_back(t);
        while (1) {
            k = st.top();
            visit[k] = false;
            st.pop();
            if (k == t)
                break;
            sol.push_back(k);
        }
        
        sort(sol.begin(), sol.end());
        ans.insert(sol);
    } 
}

int main() {
    int c = 1;     
    while (scanf("%d %d", &n, &m), n || m) {
        if (c != 1)
            printf("\n");
            
        k = x = 0;
        for (int i = 0; i < m; ++i) {
            cin >> s1 >> s2;
            
            if (ma.find(s1) == ma.end()) {
                ma[s1] = k;
                s[k] = s1;
                ++k;
            }
                
            if (ma.find(s2) == ma.end()) {
                ma[s2] = k;
                s[k] = s2;
                ++k;
            }
            
            a[ma[s1]].insert(ma[s2]);
        }
        
        memset(low, 0, sizeof(low));
        memset(high, 0, sizeof(high));
        memset(visit, false, sizeof(visit));
        
        for (int i = 0; i < n; ++i)
            if (!visit[i]) {
                visit[i] = true;
                dfs(i);
            }                     
        
        printf("Calling circles for data set %d:\n", c++);
        
        if (m != 0) 
            for (auto it = ans.begin(); it != ans.end();++it) {
                vector<int> sol = *it;
                
                for (int i = 0; i < (int)sol.size() - 1; ++i)
                    cout << s[sol[i]] << ", ";
                cout << s[sol[(int)sol.size() - 1]] << "\n";
            }
        
        ma.clear();
        ans.clear();
        for (int i = 0; i < n; ++i)
            a[i].clear();
    }
    
    return 0;
}
