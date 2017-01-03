#include <bits/stdc++.h>
using namespace std;

int t;
string s, src, dest;
string sa[205];
vector<int> a[205];
bool v[205];
pair<int, int> p;

int main() {
    cin >> t;
    cin.ignore();
    getline(cin, s);
    bool f = true;
    
    while (t--) {
        if (!f)
            cout << "\n";
            
        int k = 0;
        while (getline(cin, s)) {            
            if (s.length() == 1 && s[0] == '*')
                break;
            
            sa[k++] = s;
        }
        
        for (int i = 0; i < k; ++i)
            for (int j = i + 1; j < k; ++j)
                if (sa[i].length() == sa[j].length()) {
                    int len = sa[i].length();
                    int co = 0;
                    for (int x = 0; x < len; ++x) 
                        if (sa[i][x] != sa[j][x])
                            ++co;
                            
                    if (co == 1) {
                        a[i].push_back(j);
                        a[j].push_back(i);
                    }
                }
        
        while (getline(cin, s)) {
            if (s.empty())
                break;
                
            stringstream ss(s);
            ss >> src >> dest;
            
            int isrc = 0;
            int idest = 0;
            bool is = false;
            bool id = false;
            
            for (int i = 0; i < k; ++i) {
                if (!is)
                    if (sa[i].compare(src) == 0) {
                        isrc = i;
                        is = true;
                    }
                    
                if (!id) 
                    if (sa[i].compare(dest) == 0) {
                        idest = i;
                        id = true;
                    }
            }
            
            memset(v, false, sizeof(v));
            
            queue< pair<int, int> > q;
            q.push(make_pair(isrc, 0));
            
            int ans = 0;
            
            if (isrc != idest)
                while (!q.empty()) {
                    p = q.front();
                    q.pop();
                    
                    bool b = false;
                    for (int i = 0; i < a[p.first].size(); ++i)
                        if (!v[a[p.first][i]]) {
                            if (a[p.first][i] == idest) {
                                ans = p.second + 1;
                                b = true;
                                break;   
                            } else {
                                v[a[p.first][i]] = true;
                                q.push(make_pair(a[p.first][i], p.second + 1));
                            }
                        }
                        
                    if (b)
                        break;
                }
            
            cout << src << " " << dest << " " << ans << "\n";
        }
          
        for (int i = 0; i < k; ++i)
            a[i].clear();   
        f = false;
    }
    
    return 0;
}
