#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<int> s;
vector< vector<int> > ans;
int x;

int main() {
    while (scanf("%d", &x) != EOF) 
        v.push_back(x);
    
    if (!v.empty()) {
        s.push_back(v[0]);
        vector<int> t;
        t.push_back(v[0]);
        ans.push_back(t);
        for (int i = 1; i < v.size(); ++i) {
            auto it = lower_bound(s.begin(), s.end(), v[i]);
            if (it == s.end()) {
                s.push_back(v[i]);
                vector<int> temp = ans[(int)ans.size() - 1];
                temp.push_back(v[i]);
                ans.push_back(temp);
            } else {
                int pos = it - s.begin();
                s[pos] = v[i];
                
                if (pos == 0) {
                    vector<int> temp;
                    temp.push_back(v[i]);
                    ans[0] = temp;
                } else {
                    vector<int> temp = ans[pos - 1];
                    temp.push_back(v[i]);
                    ans[pos] = temp;
                }
            }
        }
        
        printf("%d\n-\n", (int)ans[(int)ans.size() - 1].size());
        for (int i = 0; i < ans[(int)ans.size() - 1].size(); ++i)
            printf("%d\n", ans[(int)ans.size() - 1][i]);
    } else {
        printf("0\n-\n");
    }
    
    return 0;
}
