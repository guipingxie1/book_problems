#include <bits/stdc++.h>
using namespace std;

string mv = "2147483648";

int t;
string s, k, m;
long long dp[205][205];

long long lsp(int b, int e) {
    if (dp[b][e] != -1)
        return dp[b][e];

    //cerr << b << " " << e << "\n";
    k = s.substr(b, e - b + 1);
    
    if (k.length() < 10) {
        return stol(k);
    } else if (k.length() == 10) {
        if (k < mv)
            return stol(k);
        
        long long ans = 0;    
        for (int i = 1; i < 10; ++i) {
            m = s.substr(b, i);
            ans = max(ans, stol(m) + lsp(b + i, e));
        }           
        
        return dp[b][e] = ans; 
    } 
    
    long long ans = 0;    
    for (int i = 1; i < 10; ++i) {
        m = s.substr(b, i);
        ans = max(ans, stol(m) + lsp(b + i, e));
    }         
    
    ans = max(ans, lsp(b, b + 9) + lsp(b + 10, e));  
    return dp[b][e] = ans; 
}

int main() {
    cin >> t;
    while (t--) {
        memset(dp, -1, sizeof(dp));
        cin >> s;
        if (s.empty())
            cout << "0\n";
        else cout << lsp(0, s.length() - 1) << "\n";
    }
    
    return 0;
}
