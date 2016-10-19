#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int c = 1;
    
    while (cin >> s, s.compare("end")) {
        cout << "Case " << c++ << ": ";
        
        int len = s.length();
        vector<char> v;
        v.push_back(s[0]);
        for (int i = 1; i < len; ++i) {
            bool flag = true;
            
            for (int j = 0; j < v.size(); ++j) 
                if (v[j] >= s[i]) {
                    v[j] = s[i];
                    flag = false;
                    break;
                }
            
            if (flag) 
                v.push_back(s[i]);
        }        
        
        cout << v.size() << "\n";
    }
    
    return 0;
}
