#include <bits/stdc++.h>
using namespace std;

string s;
long long a[1000005];
int n, p;
long long k, x, c;

int main() {
    while (cin >> x) {
        cin.ignore();
        
        if (cin.eof())
            break;
        
        n = 0;
        getline(cin, s);
        stringstream ss(s);
        
        while (ss >> k) 
            a[n++] = k;
        
        k = 0;
        c = 1;
        for (int i = n - 2; i >= 0; --i) {
            k += (a[i] * c * (long long)(n - 1 - i));
            c *= x; 
        }
        
        cout << k << "\n";
    }
    
    return 0;
}
