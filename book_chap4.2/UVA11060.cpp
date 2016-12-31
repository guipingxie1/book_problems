#include <bits/stdc++.h>
using namespace std;

int n, m, t;
vector<int> a[105];
int in[105];
map<string, int> ma;
string s[105];
string s1, s2;

int main() {
    int c = 1;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
            ma[s[i]] = i;
        }
        
        memset(in, 0, sizeof(in));
        
        scanf("%d", &m);
        while (m--) {
            cin >> s1 >> s2;
            a[ma[s1]].push_back(ma[s2]);
            ++in[ma[s2]];
        }
        
        vector<int> ans;
        priority_queue< int, vector<int>, greater<int> > q;
        for (int i = 0; i < n; ++i)
            if (in[i] == 0)
                q.push(i);   
            
        while (!q.empty()) {
            t = q.top();
            ans.push_back(t);
            q.pop();
            
            for (int i = 0; i < a[t].size(); ++i) {
                --in[a[t][i]];
                
                if (in[a[t][i]] == 0) 
                    q.push(a[t][i]);
            }
        }
        
        printf("Case #%d: Dilbert should drink beverages in this order: ", c++);
        for (int i = 0; i < (int)ans.size() - 1; ++i)
            cout << s[ans[i]] << " ";
        cout << s[ans[(int)ans.size() - 1]] << ".\n\n";
        
        for (int i = 0; i < n; ++i)
            a[i].clear();
            
        ma.clear();
    }
    
    return 0;
}
