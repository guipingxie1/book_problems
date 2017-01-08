#include <bits/stdc++.h>
using namespace std;

string s;
vector< map<char, char> > v;
map<int, int> m;

int main() {
    while (1) {
        m.clear();
        v.clear();
        map<char, char> ig;
        v.push_back(ig);
        cin >> s;
        if (s[0] == '#')
            break;
            
        map<char, char> vm;  
            
        while (1) {
            vm[s[2]] = s[0];
            vm[s[6]] = s[4];
            vm[s[10]] = s[8];
            vm[s[14]] = s[12];
            vm[s[18]] = s[16];
            v.push_back(vm);
            cin >> s;
            
            if (s[0] == 'e')
                break;
        }
        
        for (int i = 1; i < v.size(); ++i) {
            int c = 0;
        
            for (int j = 1; j < v.size(); ++j)
                if (j != i) {
                    if (v[j]['P'] != v[i]['P'])
                        ++c;
                        
                    if (v[j]['G'] != v[i]['G'])
                        ++c;
                        
                    if (v[j]['S'] != v[i]['S'])
                        ++c;
                        
                    if (v[j]['A'] != v[i]['A'])
                        ++c;
                        
                    if (v[j]['N'] != v[i]['N'])
                        ++c;
                }
                
            m[c] = i;
        }
        
        cout << m.begin() -> second << "\n";
    }
    
    return 0;
}
