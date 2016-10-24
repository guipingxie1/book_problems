#include <bits/stdc++.h>
using namespace std;

bool adj[26][26];
bool visited[26];

bool no_adj(int n) {
    for (int i = 0; i < 26; ++i)
        if (adj[n][i])
            return false;
            
    return true;
}

void bfs(vector<int> v) {
    int tree = 0;
    int acorn = 0;
    
    for (int i = 0; i < v.size(); ++i) {
        if (!visited[v[i]]) {
            queue<int> q;
            q.push(v[i]);
            visited[v[i]] = true;
            
            if (no_adj(v[i])) {
                ++acorn;
            } else {
                ++tree;
                
                while (!q.empty()) {
                    int t = q.front();
                    q.pop();
                    for (int j = 0; j < 26; ++j) 
                        if (adj[t][j])
                            if (!visited[j]) {
                                visited[j] = true;
                                q.push(j);
                            }                    
                }
            }                   
        }
    }
    
    cout << "There are " << tree << " tree(s) and " << acorn << " acorn(s).\n";
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    
    while (t--) {
        memset(adj, false, sizeof(adj));
        memset(visited, false, sizeof(visited));
        
        string s;
        while (true) {
            getline(cin, s);
            if (s[0] == '*')
                break;
                
            adj[s[1] - 'A'][s[3] - 'A'] = adj[s[3] - 'A'][s[1] - 'A'] = true;                        
        }
        
        vector<int> v;
        getline(cin , s);
        for (int i = 0; i < s.length(); i += 2)
            v.push_back(s[i] - 'A');
            
        bfs(v);
    }
    
    return 0;
}
