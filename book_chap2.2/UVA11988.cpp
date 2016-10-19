#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        int len = s.length();
        deque< vector<char> > q;
        vector<char> start;
        q.push_back(start);
        
        bool is_front = false;
        bool is_back = true;
        for (int i = 0; i < len; ++i) {
            if (s[i] == '[') {
                is_front = true;
                is_back = false;
                
                vector<char> v;
                q.push_front(v);
            } else if (s[i] == ']') {
                is_back = true;
                is_front = false;
            } else if (is_front) {
                q.front().push_back(s[i]);
            } else if (is_back) {
                q.back().push_back(s[i]);
            }
        }
        
        for (int i = 0; i < q.size(); ++i) {
            vector<char> v = q[i];
            for (int j = 0; j < v.size(); ++j)   
                cout << v[j];
        }
        
        cout << "\n";
    }
    
    return 0;
}
