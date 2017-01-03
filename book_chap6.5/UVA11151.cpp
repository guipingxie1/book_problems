#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

string s;
int t;

int lcp(int b, int e) {
    if (b > e)
        return 0;
        
    if (b == e)
        return 1;
    
    if (dp[b][e] != -1)
        return dp[b][e];
    
    if (s[b] == s[e])
        return dp[b][e] = 2 + lcp(b + 1, e - 1);
    return dp[b][e] = max(lcp(b + 1, e), lcp(b, e - 1));
}

int main() {
    cin >> t;
    cin.ignore();
    while (t--) {
        memset(dp, -1, sizeof(dp));
        getline(cin, s);
        cout << lcp(0, s.length() - 1) << endl;
    }
    
    return 0;
}
