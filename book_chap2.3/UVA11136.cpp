#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y;
    while (cin >> n, n) {
        priority_queue< pair<int, int> > g;
        priority_queue< pair<int, int> > l;
        set<int> reached;
        
        long long sum = 0;
        int i = 0;
        while (n--) {
            cin >> x;
            while (x--) {
                cin >> y;
                g.push(make_pair(y, i));
                l.push(make_pair(-1 * y, i));
                ++i;
            }
            
            while (reached.find(g.top().second) != reached.end())
                g.pop();
                
            while (reached.find(l.top().second) != reached.end() || l.top().second == g.top().second)
                l.pop();
                
            sum += (g.top().first + l.top().first);
            reached.insert(g.top().second);
            reached.insert(l.top().second);
            g.pop();
            l.pop();
        }
        
        cout << sum << "\n";
    }
    
    return 0;
}
