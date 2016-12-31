#include <bits/stdc++.h>
using namespace std;

int n, m, k, t;
vector<int> a[105];
string s;

int main() {
    while (cin >> n, n) {
        cin.ignore();
        while (getline(cin, s)) {
            if (s[0] == '0')
                break;
                                
            stringstream ss(s);
            ss >> k;
            
            while (ss >> m) {
                a[k].push_back(m);
                a[m].push_back(k);
            }                
        }
        
        int c = 0;
        if (n != 1) {
            for (int i = 1; i <= n; ++i) {
                set<int> s;
                
                queue<int> q;
                int start = (i + n + 1) % n;
                if (start == 0)
                    start = n;
                    
                q.push(start);
                s.insert(start);
                
                while (!q.empty()) {
                    t = q.front();
                    q.pop();
                    
                    for (int j = 0; j < a[t].size(); ++j) 
                        if (a[t][j] != i && s.find(a[t][j]) == s.end()) {
                            q.push(a[t][j]);
                            s.insert(a[t][j]);
                        }
                }
                
                if (s.size() != n - 1) 
                    ++c;
            }
        }
        
        cout << c << "\n";
        
        for (int i = 1; i <= n; ++i)
            a[i].clear();
    }
    
    return 0;
}
