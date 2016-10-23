#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int n;
    map<int, int> m;
    
    int id, p;
    priority_queue< pair<int, int> > q;
    while (getline(cin, s)) {
        if (s.length() == 1)
            break;   
        
        stringstream ss(s);
        ss >> s >> id >> p;
        
        m[id] = p;
        q.push(make_pair(-1 * p, -1 * id));
    }
    
    cin >> n;
    
    while (n--) {
        id = q.top().second;
        p = q.top().first;
        cout << -1 * id << "\n";
        
        q.pop();
        q.push(make_pair(p - m[-1 * id], id));
    }
    
    return 0;
}
