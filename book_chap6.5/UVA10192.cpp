#include <bits/stdc++.h>
using namespace std;

string s1, s2;

int main() {
    int c = 1;
    while (1) {
        getline(cin, s1);
        getline(cin, s2);
        
        if (s1[0] == '#')
            break;
            
        int len1 = s1.length();
        int len2 = s2.length();
        
        int dp[len1 + 1][len2 + 1];
        
        for (int i = 0; i <= len1; ++i)
            dp[i][0] = 0;
            
        for (int i = 1; i <= len2; ++i)
            dp[0][i] = 0;
            
        for (int i = 0; i < len1; ++i)
            for (int j = 0; j < len2; ++j) {
                if (s1[i] == s2[j])
                    dp[i + 1][j + 1] = 1 + dp[i][j];
                else dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }                
            
        cout << "Case #" << c++ << ": you can visit at most " << dp[len1][len2] << " cities.\n";
    }
    
    return 0;
}
