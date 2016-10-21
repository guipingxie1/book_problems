#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    string ss;
    getline(cin, ss);
    getline(cin, ss);
    
    while (t--) {
        string s;
        int count = 0;
        map<string, int> m;
        bool flag = true;
        while(getline(cin, s)) {
            if (s.empty()) {
                for (auto it = m.begin(); it != m.end(); ++it) {
                    cout << it -> first;
                    printf(" %.4f\n", (double)(it -> second) * (double)100 / (double)(count));
                } 
                
                if (t)
                    cout << "\n";
                    
                flag = false;
                
                break;
            } else {
                if (m.find(s) != m.end())
                    m[s]++;
                else m[s] = 1;
                ++count;
            }
        }
        
        if (flag) {
            for (auto it = m.begin(); it != m.end(); ++it) {
                cout << it -> first;
                printf(" %.4f\n", (double)(it -> second) * (double)100 / (double)(count));
            } 
            
            if (t)
                cout << "\n";
                
            m.clear();
        }
    } 
   
    return 0;
}
