#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, k, m, p, x;
    string s;
    cin >> t;
    
    while (t--) {            
        cin >> n >> k >> m;
        int co = 0;
        bool is_left = true;
        
        int times[m];
        
        // time, index
        queue< pair<int, int> > left;
        queue< pair<int, int> > right;
        int si = 0;
        
        for (int i = 0; i < m; ++i) {
            cin >> x >> s;
            if (s[0] == 'l') 
                left.push(make_pair(x, i));
            else right.push(make_pair(x, i));
        }
  
        while (!(left.empty() && right.empty())) {
            if ((!left.empty() && left.front().first <= co) || (!right.empty() && right.front().first <= co)) {
                if (is_left) {
                    while (!left.empty() && left.front().first <= co && si < n) {
                        ++si;
                        times[left.front().second] = co + k;
                        left.pop();
                    }
                } else {
                    while (!right.empty() && right.front().first <= co && si < n) {
                        ++si;
                        times[right.front().second] = co + k;
                        right.pop();
                    }
                }
                
                is_left = !is_left;
                si = 0;
                co += k;
            } else {
                int mi = 100000000;
                if (!left.empty())
                    mi = min(mi, left.front().first);
                    
                if (!right.empty())
                    mi = min(mi, right.front().first);
                    
                co = mi;
            }
        }  
               
        for (int i = 0; i < m; ++i)
            cout << times[i] << "\n";
        
        if (t)
            cout << "\n";
    }

    return 0;
}
