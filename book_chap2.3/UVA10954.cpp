#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y;
    
    while (cin >> n, n) {
        long long a;
        priority_queue<long long> q;
        for (int i = 0; i < n; ++i) {
            cin >> a;
            q.push(-1 * a);
        }
                
        long long c = 0;
        while (q.size() != 1) {
            x = q.top();
            q.pop();
            y = q.top();
            q.pop();
            c -= (x + y);
            q.push(x + y);
        }
        
        cout << c << "\n";
    }
    
    return 0;
}
