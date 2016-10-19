#include <bits/stdc++.h>
using namespace std;

bool cont(queue<int> a[], int n) {
    for (int i = 1; i <= n; ++i)
        if (!a[i].empty())
            return true;
            
    return false;
}

int main() {
    int t, n, s, q, x, y;
    cin >> t;
    
    while (t--) {
        cin >> n >> s >> q;
        queue<int> a[n + 1];
        
        for (int i = 1; i <= n; ++i) {
            cin >> x;
            for (int j = 0; j < x; ++j) {
                cin >> y;
                a[i].push(y);
            }
        }
        
        int co = 0;
        stack<int> st;
        int start = 1;
        
        while (cont(a, n)) {
            while (st.size() < s && !a[start].empty()) {
                x = a[start].front();
                st.push(x);
                a[start].pop();
                ++co;
            }
            
            co += 2;            // move stations
            
            if (start == n)
                start = 1;
            else ++start;
            
            while (!st.empty() && a[start].size() < q) {
                if (st.top() == start) {
                    st.pop();
                } else {
                    x = st.top();
                    st.pop();
                    a[start].push(x);
                }
                
                ++co;
            }
            
            while (!st.empty() && st.top() == start) {
                ++co;
                st.pop();
            }
        }
        
        cout << co << "\n";
    }
    
    return 0;
}
