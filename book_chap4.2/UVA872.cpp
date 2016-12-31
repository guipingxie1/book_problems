#include <bits/stdc++.h>
using namespace std;

int t;
bool b[26];
int in[26];
int m;
vector<int> a[26];
string s;
string n;

void top(int k, int c, vector<char> v) {
    if (c == m) {
        for (int i = 0; i < m - 1; ++i)
            cout << v[i] << " ";
        cout << v[m - 1] << "\n";
        return;
    }
    
    for (int i = 0; i < 26; ++i) 
        if (b[i] && (!(k & 1 << i)) && in[i] == 0) {
            for (int j = 0; j < a[i].size(); ++j)
                --in[a[i][j]];
                
            v.push_back((char)('A' + i));
            top(k | (1 << i), c + 1, v);
            v.pop_back();
            
            for (int j = 0; j < a[i].size(); ++j)
                ++in[a[i][j]];
        }    
    
}

int main() {
    cin >> t;
    cin.ignore();
    getline(cin, s);
    
    bool f = true;
    while (t--) {
        if (!f)
            cout << "\n";
            
        memset(b, false, sizeof(b));
        memset(in, 0, sizeof(in));
        
        m = 0;
        
        while (getline(cin, s)) {
            if (s.empty())
                break;
            
            stringstream ss(s);
            while (ss >> n) {
                if (n.length() == 1) {
                    b[n[0] - 'A'] = true;
                    ++m;
                } else {
                    ++in[n[2] - 'A'];
                    a[n[0] - 'A'].push_back(n[2] - 'A');
                }
            }
        }
        
        bool has = false;
        for (int i = 0; i < 26; ++i)
            if (b[i] && in[i] == 0)
                has = true;
        
        vector<char> ig;        
        if (has)
            top(0, 0, ig);
        else cout << "NO\n";
        
        for (int i = 0; i < 26; ++i)
            a[i].clear();
            
        f = false;
    }
    
    return 0;
}
