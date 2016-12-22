#include <bits/stdc++.h>
using namespace std;

vector<int> len[52];

int main() {
    string s, in;
    int n;
    cin >> s >> n;
    
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] >= 'a' && s[i] <= 'z')
            len[s[i] - 'a'].push_back(i);
        else len[s[i] - 'A' + 26].push_back(i);
    }
    
    while (n--) {
        cin >> in;
        int s = 0;
        int j = 0;
        int end;
        int idx = 0;
        while (idx != in.length()) {
            if (in[idx] >= 'a' && in[idx] <= 'z') {
                auto it = lower_bound(len[in[idx] - 'a'].begin(), len[in[idx] - 'a'].end(), j);
                if (it == len[in[idx] - 'a'].end()) {
                    j = -1;
                    break;
                } else {
                    if (j == *it) {
                        ++j;
                        end = j - 1;
                        
                        if (idx == 0)
                            s = j - 1;
                    } else {
                        j = *it + 1;
                        end = *it;
                        
                        if (idx == 0)
                            s = j - 1;
                    }
                }
            } else {
                auto it = lower_bound(len[in[idx] - 'A' + 26].begin(), len[in[idx] - 'A' + 26].end(), j);
                if (it == len[in[idx] - 'A' + 26].end()) {
                    j = -1;
                    break;
                } else {
                    if (j == *it) {
                        ++j;
                        end = j - 1;
                        
                        if (idx == 0)
                            s = j - 1;
                    } else {
                        j = *it + 1;
                        end = *it;
                        
                        if (idx == 0)
                            s = j - 1;
                    }
                }
            }
            ++idx;
        }
        
        if (j == -1)
            printf("Not matched\n");
        else printf("Matched %d %d\n", s, end);
    }
    
    return 0;
}
