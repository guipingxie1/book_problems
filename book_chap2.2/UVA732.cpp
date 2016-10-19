#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int n;

void catalan(int t, int f, string s, int idx) {
    if (t == 0) {
        for (int i = 0; i < f; ++i)
            s += 'f';
        
        stack<char> st;
        
        int i = 0;
        string ss = "";
        for (int j = 0; j < s.length(); ++j) {
            if (s[j] == 't') {
                st.push(s1[i++]);
            } else {
                ss += st.top();
                st.pop();
            }
        }            
        
        if (ss.compare(s2) == 0) {
            for (int j = 0; j < s.length() - 1; ++j) {
                if (s[j] == 't')
                    cout << "i ";
                else cout << "o ";
            }
            
            cout << "o\n";
        }
        
        return;
    }
    
    if (t == f) {
        catalan(t - 1, f, s + 't', idx);
    }
    
    if (f > t) {
        catalan(t - 1, f, s + 't', idx);
        
        stack<char> st;
        int i = 0;
        for (int j = 0; j < s.length(); ++j) {
            if (s[j] == 't') 
                st.push(s1[i++]);
            else st.pop();
        }
        
        if (s2[idx] == st.top())
            catalan(t, f - 1, s + 'f', idx + 1);
    }
}

int main() {
    while (cin >> s1 >> s2) {  
        n = s1.length();
        cout << "[\n";
        catalan(n, n, "", 0);
        cout << "]\n";      
    }
    
    return 0;
}
