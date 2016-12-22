#include <bits/stdc++.h>
using namespace std;

int len, n;
int a[22];
map< int, vector<int> > m;

int main() {
    string s;
    while (getline(cin, s)) {
        if (s.empty())
            break;
            
        stringstream ss(s);    
        ss >> len >> n;
        for (int i = 0; i < n; ++i)
            ss >> a[i];
            
        vector<int> v;
        m[0] = v;    
        bool cont = true;
        for (int i = 0; i < n && cont; ++i) 
            for (int j = len; j >= a[i]; --j)
                if (m.find(j) == m.end() && m.find(j - a[i]) != m.end()) {
                    vector<int> mv = m[j - a[i]];
                    mv.push_back(a[i]);                                        
                    m[j] = mv;
                    
                    if (j == len) {
                        cont = false;
                        break;                        
                    }
                }
                
        auto it = m.lower_bound(len);
        if (it == m.end()) 
            --it;
        
        v = it -> second;
        for (int i = 0; i < v.size(); ++i)
            printf("%d ", v[i]);
        printf("sum:%d\n", it -> first);
        
        m.clear();
    }    
    
    return 0;
}
