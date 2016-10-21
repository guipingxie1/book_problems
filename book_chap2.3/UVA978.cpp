#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, x, y, k;
    cin >> t;
    while (t--) {
        cin >> n >> x >> y;
        priority_queue<int> g;
        priority_queue<int> b;
        
        for (int i = 0; i < x; ++i) {
            cin >> k;
            g.push(k);
        }
            
        for (int i = 0; i < y; ++i) {
            cin >> k;
            b.push(k);
        }
        
        while (!g.empty() && !b.empty()) {
            int gg[n];
            int bb[n];
            
            if (g.size() < n || b.size() < n) {
                int k = min(g.size(), b.size());
                for (int i = 0; i < k; ++i) {
                    gg[i] = g.top();
                    g.pop();
                    bb[i] = b.top();
                    b.pop();
                }
                
                for (int i = 0; i < k; ++i) {
                    if (gg[i] > bb[i]) {
                        g.push(gg[i] - bb[i]);
                    } else if (bb[i] > gg[i]) {
                        b.push(bb[i] - gg[i]);
                    }
                }
            } else {
                for (int i = 0; i < n; ++i) {
                    gg[i] = g.top();
                    g.pop();
                    bb[i] = b.top();
                    b.pop();
                }
                
                for (int i = 0; i < n; ++i) {
                    if (gg[i] > bb[i]) {
                        g.push(gg[i] - bb[i]);
                    } else if (bb[i] > gg[i]) {
                        b.push(bb[i] - gg[i]);
                    }
                }
            }
        }
        
        if (g.empty() && b.empty()) {
            cout << "green and blue died\n";
        } else if (!g.empty()) {
            cout << "green wins\n";
            while (!g.empty()) {
                cout << g.top() << "\n";
                g.pop();
            }
        } else {
            cout << "blue wins\n";
            while (!b.empty()) {
                cout << b.top() << "\n";
                b.pop();
            }
        }
        
        if (t)
            cout << "\n";
    }
    
    return 0;
}
