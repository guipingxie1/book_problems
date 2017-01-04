#include <bits/stdc++.h>
using namespace std;

int t, n;
string h, p;
string s[100005];
int a[100005];

int main() {
    cin >> t;
    bool f = true;
    while (t--) {
        if (!f)
            cout << "\n";
            
        cin.ignore();
        getline(cin, h);
        getline(cin, h);
        stringstream ss(h);
        n = 0;
        while (ss >> p)
            a[n++] = stoi(p);
            
        for (int i = 0; i < n; ++i) {
            cin >> p;   
            s[a[i]] = p;
        }
        
        for (int i = 1; i <= n; ++i)
            cout << s[i] << "\n";
        
        f = false;
    }
    
    return 0;
}
