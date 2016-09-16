#include <bits/stdc++.h>
using namespace std;

bool works(string s1, string s2) {
    s1.erase(remove(s1.begin(), s1.end(), ' '), s1.end());
    s2.erase(remove(s2.begin(), s2.end(), ' '), s2.end());

    int l1 = s1.length();
    int l2 = s2.length();
    if (l1 != l2)
        return false;
        
    int a[256];
    int b[256];
    
    for (int i = 0; i < 256; ++i) 
        a[i] = b[i] = 0;
    
    for (int i = 0; i < l1; ++i) {
        ++a[s1[i]];
        ++b[s2[i]];
    }
    
    for (int i = 0; i < 256; ++i)
        if (a[i] != b[i])
            return false;
                  
    return true;        
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    string s;
    getline(cin, s);

    vector<string> v; 
    while (getline(cin, s)) {
        if (s.empty()) {
            sort(v.begin(), v.end());
            
            int len = v.size();
            for (int i = 0; i < len; ++i) 
                for (int j = i + 1; j < len; ++j) 
                    if (works(v[i], v[j])) 
                        cout << v[i] << " = " << v[j] << "\n";

            cout << "\n";
            v.clear();
        } else {
            v.push_back(s);
        }
    }
    
    sort(v.begin(), v.end());
            
    int len = v.size();
    for (int i = 0; i < len; ++i) 
        for (int j = i + 1; j < len; ++j) 
            if (works(v[i], v[j])) 
                cout << v[i] << " = " << v[j] << "\n";

    return 0;
}
