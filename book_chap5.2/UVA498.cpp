#include <bits/stdc++.h>
using namespace std;

string s;
int a[105];
int n, p;
long long k;
long long x;

int main() {
    while (getline(cin, s)) {
        n = 0;
        stringstream ss(s);
        
        while (ss >> p) 
            a[n++] = p;
        
        getline(cin, s);
        stringstream in(s);
        
        k = 0;
        x = 1;
        bool f = true;
        while (in >> p) {
            for (int i = n - 1; i >= 0; --i) {
                k += (a[i] * x);
                x *= p; 
            }
            
            if (f) {
                cout << k;
                f = false;
            } else {
                cout << " " << k;
            }
            
            k = 0;
            x = 1;
        }
        
        cout << "\n";
    }
    
    return 0;
}
